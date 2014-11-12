#include "calibracion.h"
#include "ui_calibracion.h"
#include "time.h"
#include <QtSerialPort/qserialportinfo.h>
#include <QMessageBox>
#include "stdint.h"
#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_plot_grid.h"
#include <QClipboard>
extern "C" {
#include "protocol.h"
}

QT_USE_NAMESPACE_SERIALPORT



Calibracion::Calibracion(QMainWindow *parent):QMainWindow (parent),ui(new Ui::Calibracion), transactionCount(0)
{

ui->setupUi(this);


    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) ui->ComboPuertosSeries->addItem(info.portName());
    ui->ComboPuertosSeries->setFocus();
    connected=false;
    connect(&serial, SIGNAL(readyRead()), // En cuanto se estñe preparado para leer, se lanza una
            this, SLOT(readRequest()));   // petición de datos por el puerto serie
    ui->Plot1->setAutoReplot(true);
    ui->Plot1->axisAutoScale(true);
    curva1 = new QwtPlotCurve;
    curva1->setPen(QPen(Qt::red ) );
    curva1->attach(ui->Plot1);
    pos =0;postabla=0;
    Indicetabla =-1;

    QGraphicsScene *scn = new QGraphicsScene( ui->graphicsView );
    scn->setSceneRect( ui->graphicsView->rect() );
    ui->graphicsView->setScene( scn );
    //ui->graphicsView->setFixedSize( 400, 400 );
    //ui->graphicsView->
    QPixmap pix( "~\\imagen.jpg" );
    scn->addPixmap( pix );
    ui->graphicsView->show();
#ifdef debug
    ui->TabControl->setTabEnabled(1,false);
    ui->TabControl->setTabEnabled(2,false);
#else
    ui->TabControl->removeTab(2);
    ui->TabControl->removeTab(1);
   #endif
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers );
  /* const int tam = 10;
    double ejex[tam], ejey[tam];

    for (int i = 0; i< tam; i++){
        ejex[i] = i;
        ejey[i] = i*rand();
    }

    curva1->setSamples(ejex,ejey,tam);
    ui->Plot1->replot();

    double parametros[2000];
    for (int i = 0; i< 2000; i++){
        parametros[i] = 1000 + ((double) rand() / 100000);
    }*/
 //   Histograma(parametros,1000,200);


}

Calibracion::~Calibracion()
{
    delete ui;
}
double Calibracion::CalculoSigma(double * Array, int tam){
    double promedio = 0.0,sigma = 0.0;
    double * p = Array;
    for (int i= 0; i< tam; i++){
        promedio += *p;
        p++;
    }
    promedio /=tam;
    p= Array;
    for (int i= 0; i< tam; i++){
        sigma +=  (( *p -promedio) * (*p -promedio));
        p++;
    }

    sigma = sqrt(sigma/tam);
    return sigma;

}
double Calibracion::CalculoPromedio(double * Array, int tam){
     double promedio = 0.0;
     double * p = Array;
     for (int i= 0; i< tam; i++){
         promedio += *p;
         p++;
     }
     promedio /=tam;
     return promedio;
}

void Calibracion::readRequest()

{
    int posicion,tam;
    char * frame;
    unsigned char command;

    request.append(serial.readAll()); // Añade el contenido del puerto serie USB al array de bytes 'request'
    // así vamos acumulando  en el array la información que va llegando

    // Busca la posición del primer byte de fin de trama (0xFD) en el array
    posicion=request.indexOf((char)STOP_FRAME_CHAR,0);

    //Metodo poco eficiente pero seguro...
    while (posicion>0)
    {
        frame=request.data(); // Puntero de trama al inicio del array de bytes
        tam=posicion-1;       //Caracter de inicio y fin no cuentan en el tamaño
        // Descarta posibles bytes erroneos que no se correspondan con el byte de inicio de trama
        while (((*frame)!=(char)START_FRAME_CHAR)&&(tam>0)) // Casting porque Qt va en C++ (en C no hace falta)
        {
            frame++;  // Descarta el caracter erroneo
            tam--;    // como parte de la trama recibida
        }

        // A. Disponemos de una trama encapsulada entre dos caracteres de inicio y fin, con un tamaño 'tam'
        if (tam >  0)
        {   //Paquete aparentemente correcto, se puede procesar
            frame++;  //Quito el byte de arranque (START_FRAME_CHAR, 0xFC)
            //Y proceso normalmente el paquete
            // Paso 1: Destuffing y cálculo del CRC. Si todo va bien, obtengo la trama
            // con valores actualizados y sin bytes de checksum
            tam=destuff_and_check_checksum((unsigned char *)frame,tam);
            // El tamaño se actualiza (he quitado 2bytes de CRC, mas los de "stuffing")
            if (tam>=0)
            {

                        command=decode_command_type(frame,0)); // Obtencion del byte de Comando



                            switch(command)
                            {
                                //Por ahora no se han implementado todos los comandos

                                case COMANDO_DATO:{
                                PARAM_COMANDO_DATO parametro;
                                extract_packet_command_param(frame,sizeof(parametro),&parametro);

                                if(pos < 999){
                                    array[pos] = (double) parametro.dato;
                                    pos++;
                                }else{
                                    //Lanzar la funcion correspondiente
                                    Histograma(&array[0],400,100);
                                    pos = 0;
                                }
                            }
                                    //Aqui recibimos el dato de tipo long y significará algo

                                break;

                            case COMANDO_SENSOR:{
                                    PARAM_COMANDO_SENSOR parametro;
                                    extract_packet_command_param(frame,sizeof(parametro),&parametro);
                                    if(PosData < Findata ){ //Rellenar array
                                        *data = floor((double) parametro.datoint);
                                        data++; //Movemos el puntero
                                        PosData++;//Actualizamos el tamaño

                                    }else{

                                        QTableWidgetItem * item = new QTableWidgetItem();

                                        item->setText(QString::number( CalculoPromedio(Pdata,Findata) ) );
                                        ui->tableWidget->setItem(Indicetabla,1,item);
                                        QTableWidgetItem * item2 = new QTableWidgetItem();
                                        item2->setText(QString::number( CalculoSigma(Pdata,Findata)    ) );
                                        ui->tableWidget->setItem(Indicetabla,2,item2);

                                    }

                            }
                                break;
                                case COMANDO_NO_IMPLEMENTADO:
                                {
                                        PARAM_COMANDO_NO_IMPLEMENTADO parametro;
                                        extract_packet_command_param(frame,sizeof(parametro),&parametro);
                                        //sprintf(mensaje,statusLabel->setText(tr(, parametro.command);
                                    //    ui->statusLabel->setText(tr("Status: Comando rechazado,"));


                                }
                                break;

                                //Falta por implementar la recepcion de mas paquetes.de respuesta

                                default:

                                    break;

                            }
                    }


        }

        request.remove(0,posicion+1);
        posicion=request.indexOf((char)STOP_FRAME_CHAR,0);
    }
}




void Calibracion::Histograma(double * datos,int tam_datos, int NumIntervalos )

{
    int i;
    double max = 0.0,min = 0.0;
    double  separacion, l_intervalo;
    double *ejex, *ejey;

    ejex = new double[NumIntervalos];
    ejey = new double[NumIntervalos];
    double * Hist = new double[NumIntervalos];
    obtenerMaxMin(datos,tam_datos,&min,&max);
    Inicializar(Hist,NumIntervalos);
    Inicializar(ejex,NumIntervalos);
    Inicializar(ejey,NumIntervalos);
    separacion = max-min;
    l_intervalo=separacion/NumIntervalos; // Cuanto va a medir cada intervalo
  //  double norma = 1.0/(tam_datos*l_intervalo);

        for (i=0; i<tam_datos; i++) {
            double valor_i=datos[i];
            int intervalo=0;
            intervalo=(valor_i-min)/l_intervalo;
            Hist[intervalo]+=1;
        }
       // for (i=0; i<NumIntervalos; i++) { Hist[i]*=norma; }


        for ( i = 0; i<NumIntervalos; i++){
            ejex[i] = min + (i* l_intervalo) ;
            ejey[i] = Hist[i];
        }




        curva1->detach();
        delete curva1;
        curva1 = new QwtPlotCurve;
        curva1->setPen(QPen(Qt::red ) );
        curva1->setSamples(ejex,ejey,NumIntervalos);
        curva1->attach(ui->Plot1);
        ui->Plot1->replot();
        QString s;
        s.setNum(0);
        s.setNum(CalculoSigma(datos,tam_datos));
        ui->Resutlado->setText(s);
}


void Calibracion::Inicializar(double *datos, int tam)
{
         int j;
        for (j=0; j<tam; j++) {
            datos[j]=0;
        }
}

void Calibracion::obtenerMaxMin(double *data, int n, double *min, double *max)
{
    int i;
    *min=data[0];
    *max=data[0];
    for (i=0; i<n; i++) {
         double valor_i=data[i];
           if (valor_i<*min) {
             *min=valor_i;
            }
            else if (valor_i>*max) {
                *max=valor_i;
            }
       }
}



void Calibracion::startSlave()
{
    if (serial.portName() != ui->ComboPuertosSeries->currentText()) {
        serial.close();
        serial.setPort(ui->ComboPuertosSeries->currentText());

        if (!serial.open(QIODevice::ReadWrite)) {
         //   processError(tr("No puedo abrir el puerto %1, error code %2").arg(serial.portName()).arg(serial.error()));

            return;
        }

        if (!serial.setBaudRate(9600)) {
           // processError(tr("No puedo establecer tasa de 9600bps en el puerto %1, error code %2").arg(serial.portName()).arg(serial.error()));

            return;
        }

        if (!serial.setDataBits(QSerialPort::Data8)) {
           // processError(tr("No puedo establecer 8bits de datos en el puerto %1, error code %2").arg(serial.portName()).arg(serial.error()));

            return;
        }

        if (!serial.setParity(QSerialPort::NoParity)) {
          //  processError(tr("NO puedo establecer parida en el puerto %1, error code %2").arg(serial.portName()).arg(serial.error()));

            return;
        }

        if (!serial.setStopBits(QSerialPort::OneStop)) {
           // processError(tr("No puedo establecer 1bitStop en el puerto %1, error code %2").arg(serial.portName()).arg(serial.error()));

            return;
        }

        if (!serial.setFlowControl(QSerialPort::NoFlowControl)) {
          //  processError(tr("No puedo establecer el control de flujo en el puerto %1, error code %2").arg(serial.portName()).arg(serial.error()));

            return;
        }
    }

    QMessageBox box;
    box.setText("Conectado");



    connected=true;
#ifdef debug
    ui->TabControl->setTabEnabled(1,true);
    ui->TabControl->setTabEnabled(2,true);
#else
    ui->TabControl->removeTab(0);

    ui->TabControl->addTab(ui->CalADC,"Calibracion");
#endif
    box.exec();
}

void Calibracion::on_BotonConectar_clicked()
{
    startSlave();
}

void Calibracion::EnviarComando(unsigned int comando){
    char paquete[MAX_FRAME_SIZE];
    int size;
    PARAM_COMANDO_DATO parametro;

    parametro.peticion = comando; //Peticion de dato float para  lo que
    size=create_frame((unsigned char *)paquete, COMANDO_DATO, &parametro, sizeof(parametro), MAX_FRAME_SIZE);

if (size>0) serial.write(paquete,size);

}

void Calibracion::on_pushButton_clicked()
{
    EnviarComando(0x0001);
}

void Calibracion::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = new QTableWidgetItem();
    item->setText(ui->lineEdit->text());
   // ui->tableWidget->insertRow(1);
    //ui->tableWidget->item(ui->tableWidget->rowCount()+1,1)->setText(ui->lineEdit->text());
    int j = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(j);
    ui->tableWidget->setItem(j,0,item);
   // ui->tableWidget->setEnabled(false);
    data = NULL;
    PosData =0;
    Indicetabla++;
    switch(ui->comboBox->currentIndex()){
    case 0: {
        data =  new double[100];
        Findata = 100;
    }
    break;
    case 1:{
        data = new double[200];
        Findata = 200;
    }break;
    case 2:{
        data = new double[500];
        Findata = 500;
    }
    case 3:{
        data = new double[1000];
        Findata = 1000;
    }
    break;
    default:break;

    }
    //Copiamos el puntero
    Pdata = data;
    //Actualizamos el numero de medidas que se van a realizar
   // postablafin = ui->tableWidget->rowCount(); //Numero de filas en la tabla (la primera es 0)
   // postabla = 0;
    char paquete[MAX_FRAME_SIZE];
    int size;
    PARAM_COMANDO_SENSOR parametro;

    parametro.peticion = Findata+1; //Peticion de dato int del ADC
    parametro.sensor = (char) ui->ComboSensores->currentIndex();
    size=create_frame((unsigned char *)paquete, COMANDO_SENSOR, &parametro, sizeof(parametro), MAX_FRAME_SIZE);

    if (size>0) serial.write(paquete,size);
    ui->CodigoText->setEnabled(true);
    ui->GenerarCodigo->setEnabled(true);
}



void Calibracion::on_GenerarCodigo_clicked()
{

                QString temporal;
                int index = ui->tableWidget->rowCount();
                temporal = "";
                ui->CodigoText->clear();
                 ui->CodigoText->insertPlainText("//Esta funcion devuelve el valor de posicion o sigma\n");
                  ui->CodigoText->insertPlainText("//Si peticion es 0x01 devuelve posicion, sino sigma\n");
                ui->CodigoText->insertPlainText("float SensorX(int8_t sensor, uint8_t peticion){\n");
                temporal = "const int8_t index =";
                temporal.append(QString::number(ui->tableWidget->rowCount()));
                temporal.append( ";\n");
                ui->CodigoText->insertPlainText(temporal);
                temporal =" float x[index] = {";
                for (int i = index-1; i >= 1; i-- )
                {
                    QTableWidgetItem * temp = ui->tableWidget->item(i,0);
                    QString tettemp = temp->text();
                    temporal.append(tettemp );
                    temporal.append(", ");
                }
                QTableWidgetItem * temp = ui->tableWidget->item(0,0);
                QString tettemp = temp->text();
                temporal.append(tettemp );
                 ui->CodigoText->insertPlainText(temporal );
                temporal =  "},\n";
                temporal.append( "         y[index] = {");

                for (int i = index-1; i >= 1; i--)
                {   //Si lo paso a voltaje pierdo precision de los LSB
                    //temporal +=  medidas[i-1].ToString() + ", ";
                    QTableWidgetItem * temp = ui->tableWidget->item(i,1);
                    QString tettemp = temp->text();
                    temporal.append(tettemp);
                    temporal.append(", ");
                }
                temp = ui->tableWidget->item(0,1);
                tettemp = temp->text();
                temporal.append(tettemp);
                ui->CodigoText->insertPlainText(temporal );
                temporal =  "},\n";
                temporal.append( "         z[index] = {");
                for (int i = index-1; i >= 1; i--)
                {
                    QTableWidgetItem * temp = ui->tableWidget->item(i,2);
                    QString tettemp = temp->text();
                    temporal.append(tettemp);
                    temporal.append(", ");
                }
                temp = ui->tableWidget->item(0,2);
                temporal.append(tettemp);
                temporal.append("}, temp;\n\n");
                ui->CodigoText->insertPlainText(temporal);
                ui->CodigoText->insertPlainText("\tif(peticion){\n");
                ui->CodigoText->insertPlainText("\t     temp = TriggerADC(uint8_t sensor);\n");
                ui->CodigoText->insertPlainText("\t     for(i=0;i<index;i++){\n");
                ui->CodigoText->insertPlainText("\t        if(temp==y[i]){\n");
                ui->CodigoText->insertPlainText("\t            return x[i];\n");
                ui->CodigoText->insertPlainText("\t        }else if(i<index-1){\n");
                ui->CodigoText->insertPlainText("\t            if(temp > y[i-1]){\n");
                ui->CodigoText->insertPlainText("\t                float pendiente = (y[i] -y[i+1])/(x[i]-x[i+1]);\n");
                ui->CodigoText->insertPlainText("\t                return (-(y[i+1] - temp)/pendiente+x[i+1]);\n");
                ui->CodigoText->insertPlainText("\t            }\n");
                ui->CodigoText->insertPlainText("\t        }\n");
                ui->CodigoText->insertPlainText("\t     }\n");
                ui->CodigoText->insertPlainText("\t}else{\n");
                ui->CodigoText->insertPlainText("\t     for(i=0;i<index;i++){\n");
                ui->CodigoText->insertPlainText("\t        if(temp==z[i]){\n");
                ui->CodigoText->insertPlainText("\t            return x[i];\n");
                ui->CodigoText->insertPlainText("\t        }else if(i<index-1){\n");
                ui->CodigoText->insertPlainText("\t            if(temp > z[i-1]){\n");
                ui->CodigoText->insertPlainText("\t                float pendiente = (z[i] -z[i+1])/(x[i]-x[i+1]);\n");
                ui->CodigoText->insertPlainText("\t                return (-(z[i+1] - temp)/pendiente+x[i+1]);\n");
                ui->CodigoText->insertPlainText("\t            }\n");
                ui->CodigoText->insertPlainText("\t        }\n");
                ui->CodigoText->insertPlainText("\t     }\n");
                ui->CodigoText->insertPlainText("\t}\n");
                ui->CodigoText->insertPlainText( "	return 0;\n");
                ui->CodigoText->insertPlainText( "}");
                QClipboard *clipboard = QApplication::clipboard();
                clipboard->setText(ui->CodigoText->toPlainText());
                QMessageBox  message;
                message.setText("El codigo resultante se ha copiado al portapapeles");
                message.exec();
}

