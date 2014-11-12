#ifndef CALIBRACION_H
#define CALIBRACION_H

#include <QMainWindow>
#include <QtSerialPort/qserialport.h> // Añadido de forma externa
#include "qwt_plot_curve.h"
#include "qwt_plot_grid.h"
#include "qwt_plot.h"

namespace Ui {
class Calibracion;
}

QT_USE_NAMESPACE_SERIALPORT

class Calibracion : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Calibracion(QMainWindow *parent = 0);
    ~Calibracion();

private slots:
    void readRequest();
    void startSlave();
    double CalculoSigma(double * Array, int tam);
    double CalculoPromedio(double * Array, int tam);
    void Inicializar(double *datos, int tam);
    void obtenerMaxMin(double *data, int n, double *min, double *max);
    void Histograma(double * datos,int tam_datos, int NumIntervalos);
    void EnviarComando(unsigned int comando);
    void on_BotonConectar_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();




    void on_GenerarCodigo_clicked();

private:
    Ui::Calibracion *ui;
    int transactionCount;
    bool connected;
    QSerialPort serial;
    QByteArray request;
    QwtPlotCurve * curva1;
    //Variables para la toma de datos
    double * data,*Pdata;
    int PosData, Findata;

    double array[1000];
    int pos, postabla, postablafin;
    //Nuevas variables porque no me acuerdo de las otras
    int Indicetabla;
};

#endif // CALIBRACION_H
