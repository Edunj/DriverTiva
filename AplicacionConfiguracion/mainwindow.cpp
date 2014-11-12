#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CheckQEI0_clicked()
{
    if(ui->CheckQEI0->isChecked() == true   ){
        ui->comboBox25->setCurrentIndex(2);
        ui->comboBox26->setCurrentIndex(2);
        ui->comboBox25->setEnabled(false);
        ui->comboBox26->setEnabled(false);
    }else{
        ui->comboBox25->setEnabled(true);
        ui->comboBox26->setEnabled(true);
    }
}

void MainWindow::on_CheckQEI1_clicked()
{
    if(ui->CheckQEI1->isChecked() == true   ){
        ui->comboBox22->setCurrentIndex(3);
        ui->comboBox23->setCurrentIndex(2);
        ui->comboBox22->setEnabled(false);
        ui->comboBox23->setEnabled(false);
    }else{
        ui->comboBox22->setEnabled(true);
        ui->comboBox23->setEnabled(true);
    }
}

void MainWindow::on_CheckPWM_clicked()
{
    if(ui->CheckPWM->isChecked() == true   ){
         ui->comboBox01->setCurrentIndex(2);
         ui->comboBox04->setCurrentIndex(2);
         ui->comboBox05->setCurrentIndex(2);
         ui->comboBox06->setCurrentIndex(2);
         ui->comboBox08->setCurrentIndex(1);
         ui->comboBox09->setCurrentIndex(1);
         ui->comboBox10->setCurrentIndex(2);
         ui->comboBox11->setCurrentIndex(2);
         ui->comboBox17->setCurrentIndex(1);
         ui->comboBox18->setCurrentIndex(1);
         ui->comboBox19->setCurrentIndex(1);
         ui->comboBox21->setCurrentIndex(1);
         ui->comboBox22->setCurrentIndex(1);
         ui->comboBox30->setCurrentIndex(1);
         ui->comboBox31->setCurrentIndex(1);
         ui->comboBox32->setCurrentIndex(1);

         ui->comboBox01->setEnabled(false);
         ui->comboBox04->setEnabled(false);
         ui->comboBox05->setEnabled(false);
         ui->comboBox06->setEnabled(false);
         ui->comboBox08->setEnabled(false);
         ui->comboBox09->setEnabled(false);
         ui->comboBox10->setEnabled(false);
         ui->comboBox11->setEnabled(false);
         ui->comboBox17->setEnabled(false);
         ui->comboBox18->setEnabled(false);
         ui->comboBox19->setEnabled(false);
         ui->comboBox21->setEnabled(false);
         ui->comboBox22->setEnabled(false);
         ui->comboBox30->setEnabled(false);
         ui->comboBox31->setEnabled(false);
         ui->comboBox32->setEnabled(false);

    }else{
        ui->comboBox01->setEnabled(true);
        ui->comboBox04->setEnabled(true);
        ui->comboBox05->setEnabled(true);
        ui->comboBox06->setEnabled(true);
        ui->comboBox08->setEnabled(true);
        ui->comboBox09->setEnabled(true);
        ui->comboBox10->setEnabled(true);
        ui->comboBox11->setEnabled(true);
        ui->comboBox17->setEnabled(true);
        ui->comboBox18->setEnabled(true);
        ui->comboBox19->setEnabled(true);
        ui->comboBox21->setEnabled(true);
        ui->comboBox22->setEnabled(true);
        ui->comboBox30->setEnabled(true);
        ui->comboBox31->setEnabled(true);
        ui->comboBox32->setEnabled(true);
    }

}


void MainWindow::on_CheckADC_clicked()
{
      if(ui->CheckADC->isChecked() == true   ){
          ui->comboBox01->setCurrentIndex(1);
          ui->comboBox04->setCurrentIndex(1);
          ui->comboBox05->setCurrentIndex(1);
          ui->comboBox06->setCurrentIndex(1);
          ui->comboBox10->setCurrentIndex(1);
          ui->comboBox11->setCurrentIndex(1);
          ui->comboBox12->setCurrentIndex(1);
          ui->comboBox13->setCurrentIndex(1);
          ui->comboBox14->setCurrentIndex(1);
          ui->comboBox15->setCurrentIndex(1);
          ui->comboBox16->setCurrentIndex(1);
          ui->comboBox29->setCurrentIndex(1);

          ui->comboBox01->setEnabled(false);
          ui->comboBox04->setEnabled(false);
          ui->comboBox05->setEnabled(false);
          ui->comboBox06->setEnabled(false);
          ui->comboBox10->setEnabled(false);
          ui->comboBox11->setEnabled(false);
          ui->comboBox12->setEnabled(false);
          ui->comboBox13->setEnabled(false);
          ui->comboBox14->setEnabled(false);
          ui->comboBox15->setEnabled(false);
          ui->comboBox16->setEnabled(false);
          ui->comboBox29->setEnabled(false);
      }else{
          ui->comboBox01->setEnabled(true);
          ui->comboBox04->setEnabled(true);
          ui->comboBox05->setEnabled(true);
          ui->comboBox06->setEnabled(true);
          ui->comboBox10->setEnabled(true);
          ui->comboBox11->setEnabled(true);
          ui->comboBox12->setEnabled(true);
          ui->comboBox13->setEnabled(true);
          ui->comboBox14->setEnabled(true);
          ui->comboBox15->setEnabled(true);
          ui->comboBox16->setEnabled(true);
          ui->comboBox29->setEnabled(true);
      }
}



void MainWindow::on_GenerarConfig_clicked()
{
    //defines PWM
    bool USEGENPWM0 = false,  USEGENPWM1 = false,
    USEOUTPWM0 = false, USEOUTPWM1 = false, USEOUTPWM2 = false, USEOUTPWM3 = false,
    USEOUTPWM4 = false, USEOUTPWM5 = false, USEOUTPWM6 = false, USEOUTPWM7 = false,
    USEOUTPWM8 = false, USEOUTPWM9 = false, USEOUTPWM10 = false, USEOUTPWM11 = false,
    USEOUTPWM12 = false, USEOUTPWM13 = false, USEOUTPWM14 = false, USEOUTPWM15 = false ;

    //defines ADC
    bool USEADC0 = false, USEADC0SEQ0 = false, USEADC0SEQ1 = false,
         USEADC0SEQ0IN0 = false, USEADC0SEQ0IN1 = false, USEADC0SEQ0IN2 = false, USEADC0SEQ0IN3 = false,
         USEADC0SEQ0IN4 = false, USEADC0SEQ0IN5 = false, USEADC0SEQ0IN6 = false, USEADC0SEQ0IN7 = false,
         USEADC0SEQ1IN0 = false, USEADC0SEQ1IN1 = false, USEADC0SEQ1IN2 = false, USEADC0SEQ1IN3 = false;

    //defines TOF
    bool USEPORTA = false, USEPORTB = false, USEPORTC = false, USEPORTD = false, USEPORTE = false, USEPORTF = false,
    USEPORTAPIN0 = false, USEPORTAPIN1 = false, USEPORTAPIN2 = false, USEPORTAPIN3 = false, USEPORTAPIN4 = false, USEPORTAPIN5 = false, USEPORTAPIN6 = false, USEPORTAPIN7 = false,
    USEPORTBPIN0 = false, USEPORTBPIN1 = false, USEPORTBPIN2 = false, USEPORTBPIN3 = false, USEPORTBPIN4 = false, USEPORTBPIN5 = false, USEPORTBPIN6 = false, USEPORTBPIN7 = false,
                                                                                            USEPORTCPIN4 = false, USEPORTCPIN5 = false, USEPORTCPIN6 = false, USEPORTCPIN7 = false,
    USEPORTDPIN0 = false, USEPORTDPIN1 = false, USEPORTDPIN2 = false, USEPORTDPIN3 = false, USEPORTDPIN4 = false, USEPORTDPIN5 = false, USEPORTDPIN6 = false, USEPORTDPIN7 = false,
    USEPORTEPIN0 = false, USEPORTEPIN1 = false, USEPORTEPIN2 = false, USEPORTEPIN3 = false, USEPORTEPIN4 = false, USEPORTEPIN5 = false,
    USEPORTFPIN0 = false, USEPORTFPIN1 = false, USEPORTFPIN2 = false, USEPORTFPIN3 = false, USEPORTFPIN4 = false;
    int NumeroPWM = 0;
ui->TextCode->clear();
ui->TextFuente->clear();
    //defines qei
    bool USEQEI0 = false,USEQEI1 = false;

    //Comprobación qei
    if(ui->comboBox25->currentIndex() == 2 && ui->comboBox26->currentIndex() == 2 ){
        USEQEI0 = true;
        ui->TextCode->insertPlainText("#define USEQEI0\n");
    }else{
        USEQEI0 = false;
    }
    if(ui->comboBox22->currentIndex() == 3 && ui->comboBox23->currentIndex() == 2 ){
        USEQEI1 = true;
        ui->TextCode->insertPlainText("#define USEQEI1\n");
    }else{
        USEQEI1 = false;
    }
    QString temporalPWM = "";

    //comprobacion PWM
    if(ui->comboBox32->currentIndex() == 1){

      USEOUTPWM0 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM0\n");
      temporalPWM.append("ConfigPWM(PWM0,x,y);\n");
      NumeroPWM++;
    }else{
      USEOUTPWM0 = false;
    }
    if(ui->comboBox31->currentIndex() == 1){

      USEOUTPWM1 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM1\n");
      temporalPWM.append("ConfigPWM(PWM1,x,y);\n");
      NumeroPWM++;
    }else{
       USEOUTPWM1 = false;
    }
    if(ui->comboBox06->currentIndex() == 2){

      USEOUTPWM2 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM2\n");
      temporalPWM.append("ConfigPWM(PWM2,x,y);\n");
      NumeroPWM++;
    }else{
      USEOUTPWM2 = false;
    }
    if(ui->comboBox01->currentIndex() == 2){

      USEOUTPWM3 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM3\n");
      temporalPWM.append("ConfigPWM(PWM3,x,y);\n");
      NumeroPWM++;
    }else{
      USEOUTPWM3 = false;
    }
    if(ui->comboBox04->currentIndex() == 2){

      USEOUTPWM4 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM4\n");
      temporalPWM.append("ConfigPWM(PWM4,x,y);\n");
      NumeroPWM++;
    }else{
       USEOUTPWM4 = false;
    }
    if(ui->comboBox05->currentIndex() == 2){

      USEOUTPWM5 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM5\n");
      temporalPWM.append("ConfigPWM(PWM5,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM5 = false;
    }
    if(ui->comboBox21->currentIndex() == 1){

      USEOUTPWM6 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM6\n");
      temporalPWM.append("ConfigPWM(PWM6,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM6 = false;
    }
    if(ui->comboBox22->currentIndex() == 1){

      USEOUTPWM7 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM7\n");
      temporalPWM.append("ConfigPWM(PWM7,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM7 = false;
    }
    if(ui->comboBox10->currentIndex() == 2){

      USEOUTPWM8 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM8\n");
      temporalPWM.append("ConfigPWM(PWM8,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM8 = false;
    }
    if(ui->comboBox11->currentIndex() == 2){

      USEOUTPWM9 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM9\n");
      temporalPWM.append("ConfigPWM(PWM9,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM9 = false;
    }
    if(ui->comboBox08->currentIndex() == 1){

      USEOUTPWM10 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM10\n");
      temporalPWM.append("ConfigPWM(PWM10,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM10 = false;
    }
    if(ui->comboBox09->currentIndex() == 1){

      USEOUTPWM11 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM11\n");
      temporalPWM.append("ConfigPWM(PWM11,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM11 = false;
    }
    if(ui->comboBox30->currentIndex() == 1){

      USEOUTPWM12 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM12\n");
      temporalPWM.append("ConfigPWM(PWM12,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM12 = false;
    }
    if(ui->comboBox17->currentIndex() == 1){

      USEOUTPWM13 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM13\n");
      temporalPWM.append("ConfigPWM(PWM13,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM13 = false;
    }
    if(ui->comboBox18->currentIndex() == 1){

      USEOUTPWM14 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM14\n");
      temporalPWM.append("ConfigPWM(PWM14,x,y);\n");
      NumeroPWM++;
    }else{
        USEOUTPWM14 = false;
    }
    if(ui->comboBox19->currentIndex() == 1){

      USEOUTPWM15 = true;
      ui->TextCode->insertPlainText("#define USEOUTPWM15\n");
      temporalPWM.append("ConfigPWM(PWM15,x,y);\n");
      NumeroPWM++;
    }else{
       USEOUTPWM15 = false;
    }

    if(USEOUTPWM0 || USEOUTPWM1 || USEOUTPWM2 || USEOUTPWM3 || USEOUTPWM4 ||  USEOUTPWM5 ||  USEOUTPWM6 || USEOUTPWM7){
        USEGENPWM0 = true;
        ui->TextCode->insertPlainText("#define USEGENPWM0\n");
    }else{
        USEGENPWM0 = false;
    }
    if( USEOUTPWM8 || USEOUTPWM9 || USEOUTPWM10 || USEOUTPWM11 ||  USEOUTPWM12 ||  USEOUTPWM13 || USEOUTPWM14 || USEOUTPWM15){
        USEGENPWM1 = true;
        ui->TextCode->insertPlainText("#define USEGENPWM1\n");
    }else{
        USEGENPWM1 = false;
    }


    QString temporalADC = "";
    //Comprobacion ADC
    if(ui->comboBox16->currentIndex() == 1){
        USEADC0SEQ0IN0 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ0IN0\n");
        temporalADC.append("ConfigSensorADC(ADC0);\n");
    }else{
        USEADC0SEQ0IN0 = false;
    }
    if(ui->comboBox15->currentIndex() == 1){
        USEADC0SEQ0IN1 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ0IN1\n");
        temporalADC.append("ConfigSensorADC(ADC1);\n");
    }else{
        USEADC0SEQ0IN1 = false;
    }
    if(ui->comboBox14->currentIndex() == 1){
        USEADC0SEQ0IN2 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ0IN2\n");
        temporalADC.append("ConfigSensorADC(ADC2);\n");
    }else{
        USEADC0SEQ0IN2 = false;
    }
    if(ui->comboBox29->currentIndex() == 1){
        USEADC0SEQ0IN3 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ0IN3\n");
        temporalADC.append("ConfigSensorADC(ADC3);\n");
    }else{
        USEADC0SEQ0IN3 = false;
    }
    if(ui->comboBox13->currentIndex() == 1){
        USEADC0SEQ0IN4 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ0IN4\n");
        temporalADC.append("ConfigSensorADC(ADC4);\n");
    }else{
        USEADC0SEQ0IN4 = false;
    }
    if(ui->comboBox12->currentIndex() == 1){
        USEADC0SEQ0IN5 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ0IN5\n");
        temporalADC.append("ConfigSensorADC(ADC5);\n");
    }else{
        USEADC0SEQ0IN5 = false;
    }
    if(ui->comboBox11->currentIndex() == 1){
        USEADC0SEQ0IN6 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ0IN6\n");
        temporalADC.append("ConfigSensorADC(ADC6);\n");
    }else{
        USEADC0SEQ0IN6 = false;
    }
    if(ui->comboBox10->currentIndex() == 1){
        USEADC0SEQ0IN7 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ0IN7\n");
        temporalADC.append("ConfigSensorADC(ADC7);\n");
    }else{
        USEADC0SEQ0IN7 = false;
    }
    if(ui->comboBox05->currentIndex() == 1){
        USEADC0SEQ1IN0 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ1IN0\n");
        temporalADC.append("ConfigSensorADC(ADC8);\n");
    }else{
        USEADC0SEQ1IN0 = false;
    }
    if(ui->comboBox04->currentIndex() == 1){
        USEADC0SEQ1IN1 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ1IN2\n");
        temporalADC.append("ConfigSensorADC(ADC9);\n");
    }else{
        USEADC0SEQ1IN2 = false;
    }
    if(ui->comboBox06->currentIndex() == 1){
        USEADC0SEQ1IN2 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ1IN2\n");
        temporalADC.append("ConfigSensorADC(ADC10);\n");
    }else{
        USEADC0SEQ1IN2 = false;
    }
    if(ui->comboBox01->currentIndex() == 1){
        USEADC0SEQ1IN3 = true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ1IN3\n");
        temporalADC.append("ConfigSensorADC(ADC11);\n");
    }else{
        USEADC0SEQ1IN3 = false;
    }
    if(USEADC0SEQ0IN0 || USEADC0SEQ0IN1 ||  USEADC0SEQ0IN2 || USEADC0SEQ0IN3 ||  USEADC0SEQ0IN4 || USEADC0SEQ0IN5||  USEADC0SEQ0IN6 || USEADC0SEQ0IN7){
        USEADC0SEQ0 =  true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ0\n");
    }else{
        USEADC0SEQ0 = false;
    }
    if(USEADC0SEQ1IN3 || USEADC0SEQ1IN2 ||  USEADC0SEQ1IN1 || USEADC0SEQ1IN0 ){
        USEADC0SEQ1 =  true;
        ui->TextCode->insertPlainText("#define USEADC0SEQ1\n");
    }else{
        USEADC0SEQ1 = false;
    }
    if(USEADC0SEQ0 || USEADC0SEQ1){
        USEADC0 =  true;
        ui->TextCode->insertPlainText("#define USEADC0 \n");
    }else{
        USEADC0 = false;
    }

    if(ui->CheckLCD->isChecked() == true   ){
         ui->TextCode->insertPlainText("#define USELCD \n");
    }else{

    }


    //Comprobación TOF
    QString temporalTOF;

    if(ui->comboBox35->currentIndex() == 1){
        USEPORTAPIN2 = true;
        temporalTOF.append("TOFEchoInit(PA2);\n");
        ui->TextCode->insertPlainText("#define USEPORTAPIN2 \n");
    }
    if(ui->comboBox34->currentIndex() == 1){
        USEPORTAPIN3 = true;
        temporalTOF.append("TOFEchoInit(PA3);\n");
        ui->TextCode->insertPlainText("#define USEPORTAPIN3 \n");
    }
    if(ui->comboBox33->currentIndex() == 1){
        USEPORTAPIN4 = true;
        temporalTOF.append("TOFEchoInit(PA4);\n");
         ui->TextCode->insertPlainText("#define USEPORTAPIN4 \n");
    }
    if(ui->comboBox07->currentIndex() == 1){
        USEPORTAPIN5 = true;
        temporalTOF.append("TOFEchoInit(PA5);\n");
        ui->TextCode->insertPlainText("#define USEPORTAPIN5 \n");
    }
    if(ui->comboBox08->currentIndex() == 2){
        USEPORTAPIN6 = true;
        temporalTOF.append("TOFEchoInit(PA6);\n");
        ui->TextCode->insertPlainText("#define USEPORTAPIN6 \n");
    }
    if(ui->comboBox09->currentIndex() == 2){
        USEPORTAPIN7 = true;
        temporalTOF.append("TOFEchoInit(PA7);\n");
        ui->TextCode->insertPlainText("#define USEPORTAPIN7 \n");
    }

    if(  USEPORTAPIN2  || USEPORTAPIN3 || USEPORTAPIN4  || USEPORTAPIN5  || USEPORTAPIN6  || USEPORTAPIN7 ){
        USEPORTA = true;
    }

    if(ui->comboBox02->currentIndex() == 1){
        USEPORTBPIN0 = true;
        temporalTOF.append("TOFEchoInit(PB0);\n");
        ui->TextCode->insertPlainText("#define USEPORTBPIN0 \n");
    }
    if(ui->comboBox03->currentIndex() == 1){
        USEPORTBPIN1 = true;
        temporalTOF.append("TOFEchoInit(PB1);\n");
        ui->TextCode->insertPlainText("#define USEPORTBPIN1 \n");
    }
    if(ui->comboBox28->currentIndex() == 1){
        USEPORTBPIN2 = true;
        temporalTOF.append("TOFEchoInit(PB2);\n");
        ui->TextCode->insertPlainText("#define USEPORTBPIN2 \n");
    }
    if(ui->comboBox20->currentIndex() == 1){
        USEPORTBPIN3 = true;
        temporalTOF.append("TOFEchoInit(PB3);\n");
        ui->TextCode->insertPlainText("#define USEPORTBPIN3 \n");
    }
    if(ui->comboBox06->currentIndex() == 3){
        USEPORTBPIN4 = true;
        temporalTOF.append("TOFEchoInit(PB4);\n");
        ui->TextCode->insertPlainText("#define USEPORTBPIN4 \n");
    }
    if(ui->comboBox01->currentIndex() == 3){
        USEPORTBPIN5 = true;
        temporalTOF.append("TOFEchoInit(PB5);\n");
        ui->TextCode->insertPlainText("#define USEPORTBPIN5 \n");
    }
    if(ui->comboBox32->currentIndex() == 2){
        USEPORTBPIN6 = true;
        temporalTOF.append("TOFEchoInit(PB6);\n");
        ui->TextCode->insertPlainText("#define USEPORTBPIN6 \n");
    }
    if(ui->comboBox31->currentIndex() == 2){
        USEPORTBPIN7 = true;
        temporalTOF.append("TOFEchoInit(PB7);\n");
        ui->TextCode->insertPlainText("#define USEPORTBPIN7 \n");
    }

    if(USEPORTBPIN0 || USEPORTBPIN1  || USEPORTBPIN2  || USEPORTBPIN3 || USEPORTBPIN4  || USEPORTBPIN5  || USEPORTBPIN6  || USEPORTBPIN7 ){
        USEPORTB = true;
    }

    if(ui->comboBox21->currentIndex() == 2){
        USEPORTCPIN4 = true;
        temporalTOF.append("TOFEchoInit(PC4);\n");
        ui->TextCode->insertPlainText("#define USEPORTCPIN4 \n");
    }
    if(ui->comboBox22->currentIndex() == 2){
        USEPORTCPIN5 = true;
        temporalTOF.append("TOFEchoInit(PC5);\n");
        ui->TextCode->insertPlainText("#define USEPORTCPIN5 \n");
    }
    if(ui->comboBox23->currentIndex() == 1){
        USEPORTCPIN6 = true;
        temporalTOF.append("TOFEchoInit(PC6);\n");
        ui->TextCode->insertPlainText("#define USEPORTCPIN6 \n");
    }
    if(ui->comboBox24->currentIndex() == 1){
        USEPORTCPIN7 = true;
        temporalTOF.append("TOFEchoInit(PC7);\n");
        ui->TextCode->insertPlainText("#define USEPORTCPIN7 \n");
    }
    if( USEPORTCPIN4  || USEPORTCPIN5  || USEPORTCPIN6  || USEPORTCPIN7 ){
        USEPORTC = true;
    }

    if(ui->comboBox10->currentIndex() == 3){
        USEPORTDPIN0 = true;
        temporalTOF.append("TOFEchoInit(PD0);\n");
        ui->TextCode->insertPlainText("#define USEPORTDPIN0 \n");
    }
    if(ui->comboBox11->currentIndex() == 3){
        USEPORTDPIN1 = true;
        temporalTOF.append("TOFEchoInit(PD1);\n");
        ui->TextCode->insertPlainText("#define USEPORTDPIN1 \n");
    }
    if(ui->comboBox12->currentIndex() == 2){
        USEPORTDPIN2 = true;
        temporalTOF.append("TOFEchoInit(PD2);\n");
        ui->TextCode->insertPlainText("#define USEPORTDPIN2 \n");
    }
    if(ui->comboBox13->currentIndex() == 2){
        USEPORTDPIN3 = true;
        temporalTOF.append("TOFEchoInit(PD3);\n");
        ui->TextCode->insertPlainText("#define USEPORTDPIN3 \n");
    }
    if(ui->comboBox25->currentIndex() == 1){
        USEPORTDPIN6 = true;
        temporalTOF.append("TOFEchoInit(PD6);\n");
        ui->TextCode->insertPlainText("#define USEPORTDPIN6 \n");
    }
    if(ui->comboBox26->currentIndex() == 1){
        USEPORTDPIN7 = true;
        temporalTOF.append("TOFEchoInit(PD7);\n");
        ui->TextCode->insertPlainText("#define USEPORTDPIN7 \n");
    }
    if(USEPORTDPIN0 || USEPORTDPIN1  || USEPORTDPIN2  || USEPORTDPIN3  || USEPORTDPIN6  || USEPORTDPIN7 ){
        USEPORTD = true;
    }

    if(ui->comboBox14->currentIndex() == 2){
        USEPORTEPIN0 = true;
        temporalTOF.append("TOFEchoInit(PE0);\n");
        ui->TextCode->insertPlainText("#define USEPORTEPIN0 \n");
    }
    if(ui->comboBox15->currentIndex() == 2){
        USEPORTEPIN1 = true;
        temporalTOF.append("TOFEchoInit(PE1);\n");
        ui->TextCode->insertPlainText("#define USEPORTEPIN1 \n");
    }
    if(ui->comboBox16->currentIndex() == 2){
        USEPORTEPIN2 = true;
        temporalTOF.append("TOFEchoInit(PE2);\n");
        ui->TextCode->insertPlainText("#define USEPORTEPIN2 \n");
    }
    if(ui->comboBox29->currentIndex() == 2){
        USEPORTEPIN3 = true;
        temporalTOF.append("TOFEchoInit(PE3);\n");
        ui->TextCode->insertPlainText("#define USEPORTEPIN3 \n");
    }
    if(ui->comboBox04->currentIndex() == 3){
        USEPORTEPIN4 = true;
        temporalTOF.append("TOFEchoInit(PE4);\n");
        ui->TextCode->insertPlainText("#define USEPORTEPIN4 \n");
    }
    if(ui->comboBox05->currentIndex() == 3){
        USEPORTEPIN5 = true;
        temporalTOF.append("TOFEchoInit(PE5);\n");
        ui->TextCode->insertPlainText("#define USEPORTEPIN5 \n");
    }

    if(USEPORTEPIN0 || USEPORTEPIN1  || USEPORTEPIN2  || USEPORTEPIN3  || USEPORTEPIN4  || USEPORTEPIN5 ){
        USEPORTE = true;
    }

    if(ui->comboBox30->currentIndex() == 2){
        USEPORTFPIN0 = true;
        temporalTOF.append("TOFEchoInit(PF0);\n");
        ui->TextCode->insertPlainText("#define USEPORTFPIN0 \n");
    }
    if(ui->comboBox17->currentIndex() == 2){
        USEPORTFPIN1 = true;
        temporalTOF.append("TOFEchoInit(PF1);\n");
        ui->TextCode->insertPlainText("#define USEPORTFPIN1 \n");
    }
    if(ui->comboBox18->currentIndex() == 2){
        USEPORTFPIN2 = true;
        temporalTOF.append("TOFEchoInit(PF2);\n");
        ui->TextCode->insertPlainText("#define USEPORTFPIN2 \n");
    }
    if(ui->comboBox19->currentIndex() == 2){
        USEPORTFPIN3 = true;
        temporalTOF.append("TOFEchoInit(PF3);\n");
        ui->TextCode->insertPlainText("#define USEPORTFPIN3 \n");
    }
    if(ui->comboBox27->currentIndex() == 1){
        USEPORTFPIN4 = true;
        temporalTOF.append("TOFEchoInit(PF4);\n");
        ui->TextCode->insertPlainText("#define USEPORTFPIN4 \n");
    }

    if(USEPORTFPIN0 || USEPORTFPIN1  || USEPORTFPIN2  || USEPORTFPIN3  || USEPORTFPIN4  ){
        USEPORTF = true;
    }

    //Puentes H
    QString temporalMotor;
    if( ui->ComboPuentesH->currentIndex() > 0 && NumeroPWM >=2 ){

        switch(ui->ComboPuentesH->currentIndex()){
        case 1: //un puente H dos salidas PWM
        {
            if(NumeroPWM >=2){
                temporalMotor.append("configDRVPWM(PWMA,PWMA,0,0,0,0,0,0,0,0,0,0,0,0,0,0);\n");
            ui->TextCode->insertPlainText("#define USEMOTORA \n");
            }

        }break;
        case 2: //2 puente H 4 salidas PWM
        {
            if(NumeroPWM >=4){
                temporalMotor.append("configDRVPWM(PWMA,PWMA,PWMB,PWMB,0,0,0,0,0,0,0,0,0,0,0,0);\n");
                ui->TextCode->insertPlainText("#define USEMOTORA \n");
                ui->TextCode->insertPlainText("#define USEMOTORB \n");

            }

        }break;
        case 3: //3 puente H 6 salidas PWM
        {
            if(NumeroPWM >=6){
                temporalMotor.append("configDRVPWM(PWMA,PWMA,PWMB,PWMB,PWMC,PWMC,0,0,0,0,0,0,0,0,0,0);\n");
                ui->TextCode->insertPlainText("#define USEMOTORA \n");
                ui->TextCode->insertPlainText("#define USEMOTORB \n");
                ui->TextCode->insertPlainText("#define USEMOTORC \n");

            }

        }break;
        case 4: //4 puente H 8 salidas PWM
        {
            if(NumeroPWM >=8){
                temporalMotor.append("configDRVPWM(PWMA,PWMA,PWMB,PWMB,PWMC,PWMC,PWMD,PWMD,0,0,0,0,0,0,0,0);\n");
                ui->TextCode->insertPlainText("#define USEMOTORA \n");
                ui->TextCode->insertPlainText("#define USEMOTORB \n");
                ui->TextCode->insertPlainText("#define USEMOTORC \n");
                ui->TextCode->insertPlainText("#define USEMOTORD \n");
            }

        }break;
        case 5: //5 puente H 10 salidas PWM
        {
            if(NumeroPWM >=10){
                temporalMotor.append("configDRVPWM(PWMA,PWMA,PWMB,PWMB,PWMC,PWMC,PWMD,PWMD,PWME,PWME,0,0,0,0,0,0);\n");
                ui->TextCode->insertPlainText("#define USEMOTORA \n");
                ui->TextCode->insertPlainText("#define USEMOTORB \n");
                ui->TextCode->insertPlainText("#define USEMOTORC \n");
                ui->TextCode->insertPlainText("#define USEMOTORD \n");
                ui->TextCode->insertPlainText("#define USEMOTORE \n");
            }

        }break;
        case 6: //6 puente H 12 salidas PWM
        {
            if(NumeroPWM >=12){
                temporalMotor.append("configDRVPWM(PWMA,PWMA,PWMB,PWMB,PWMC,PWMC,PWMD,PWMD,PWME,PWME,PWMF,PWMF,0,0,0,0);\n");
                ui->TextCode->insertPlainText("#define USEMOTORA \n");
                ui->TextCode->insertPlainText("#define USEMOTORB \n");
                ui->TextCode->insertPlainText("#define USEMOTORC \n");
                ui->TextCode->insertPlainText("#define USEMOTORD \n");
                ui->TextCode->insertPlainText("#define USEMOTORE \n");
                ui->TextCode->insertPlainText("#define USEMOTORF \n");
            }

        }break;
        case 7: //7 puente H 14 salidas PWM
        {
            if(NumeroPWM >=14){
                temporalMotor.append("configDRVPWM(PWMA,PWMA,PWMB,PWMB,PWMC,PWMC,PWMD,PWMD,PWME,PWME,PWMF,PWMF,PWMG,PWMG,0,0);\n");
                ui->TextCode->insertPlainText("#define USEMOTORA \n");
                ui->TextCode->insertPlainText("#define USEMOTORB \n");
                ui->TextCode->insertPlainText("#define USEMOTORC \n");
                ui->TextCode->insertPlainText("#define USEMOTORD \n");
                ui->TextCode->insertPlainText("#define USEMOTORE \n");
                ui->TextCode->insertPlainText("#define USEMOTORF \n");
                ui->TextCode->insertPlainText("#define USEMOTORG \n");
            }

        }break;
        case 8: //8 puente H 16 salidas PWM
        {
            if(NumeroPWM =16){
                temporalMotor.append("configDRVPWM(PWMA,PWMA,PWMB,PWMB,PWMC,PWMC,PWMD,PWMD,PWME,PWME,PWMF,PWMF,PWMG,PWMG,PWMH,PWMH);\n");
                ui->TextCode->insertPlainText("#define USEMOTORA \n");
                ui->TextCode->insertPlainText("#define USEMOTORB \n");
                ui->TextCode->insertPlainText("#define USEMOTORC \n");
                ui->TextCode->insertPlainText("#define USEMOTORD \n");
                ui->TextCode->insertPlainText("#define USEMOTORE \n");
                ui->TextCode->insertPlainText("#define USEMOTORF \n");
                ui->TextCode->insertPlainText("#define USEMOTORG \n");
                ui->TextCode->insertPlainText("#define USEMOTORH \n");
            }

        }break;
        }

    }


     ui->TextFuente->insertPlainText("InitReloj();\n");
    if(USEGENPWM0 || USEGENPWM1){
        ui->TextFuente->insertPlainText("initPWMS();\n");
    }
    if(USEADC0){
        ui->TextFuente->insertPlainText("InitSensorADC();\n");
    }
    if(USEQEI0 || USEQEI1){
         ui->TextFuente->insertPlainText("QeiInit();\n");
    }
    if(USEGENPWM0 || USEGENPWM1){
        ui->TextFuente->insertPlainText(temporalPWM);
    }
    if(USEADC0){
         ui->TextFuente->insertPlainText(temporalADC);
    }
    if(USEQEI0){
        ui->TextFuente->insertPlainText("QeiConfigEncoder(QEI0,X);\n");
    }
    if(USEQEI1){
        ui->TextFuente->insertPlainText("QeiConfigEncoder(QEI1,X);\n");
    }
    if(USEPORTA || USEPORTB || USEPORTC || USEPORTD || USEPORTE|| USEPORTF){
        ui->TextFuente->insertPlainText(temporalTOF);
    }
    ui->TextFuente->insertPlainText(temporalMotor);

}

void MainWindow::on_CheckLCD_clicked()
{
     if(ui->CheckLCD->isChecked() == true   ){
         ui->comboBox10->setCurrentIndex(0);
         ui->comboBox11->setCurrentIndex(0);
         ui->comboBox12->setCurrentIndex(0);
         ui->comboBox13->setCurrentIndex(0);
         ui->comboBox25->setCurrentIndex(0);
         ui->comboBox10->setEnabled(false);
         ui->comboBox11->setEnabled(false);
         ui->comboBox12->setEnabled(false);
         ui->comboBox13->setEnabled(false);
         ui->comboBox25->setEnabled(false);
     }else{
         ui->comboBox10->setEnabled(true);
         ui->comboBox11->setEnabled(true);
         ui->comboBox12->setEnabled(true);
         ui->comboBox13->setEnabled(true);
         ui->comboBox25->setEnabled(true);
     }
}




void MainWindow::on_CheckTOF_clicked()
{
    if(ui->CheckTOF->isChecked() == true  ){
        ui->comboBox01->setCurrentIndex(3);
        ui->comboBox02->setCurrentIndex(1);
        ui->comboBox03->setCurrentIndex(1);
        ui->comboBox04->setCurrentIndex(3);
        ui->comboBox05->setCurrentIndex(3);
        ui->comboBox06->setCurrentIndex(3);
        ui->comboBox07->setCurrentIndex(1);
        ui->comboBox08->setCurrentIndex(2);
        ui->comboBox09->setCurrentIndex(2);
        ui->comboBox10->setCurrentIndex(3);
        ui->comboBox11->setCurrentIndex(3);
        ui->comboBox12->setCurrentIndex(2);
        ui->comboBox13->setCurrentIndex(2);
        ui->comboBox14->setCurrentIndex(2);
        ui->comboBox15->setCurrentIndex(2);
        ui->comboBox16->setCurrentIndex(2);
        ui->comboBox17->setCurrentIndex(2);
        ui->comboBox18->setCurrentIndex(2);
        ui->comboBox19->setCurrentIndex(2);
        ui->comboBox20->setCurrentIndex(1);
        ui->comboBox21->setCurrentIndex(2);
        ui->comboBox22->setCurrentIndex(2);
        ui->comboBox23->setCurrentIndex(1);
        ui->comboBox24->setCurrentIndex(1);
        ui->comboBox25->setCurrentIndex(1);
        ui->comboBox26->setCurrentIndex(1);
        ui->comboBox27->setCurrentIndex(1);
        ui->comboBox28->setCurrentIndex(1);
        ui->comboBox29->setCurrentIndex(2);
        ui->comboBox30->setCurrentIndex(2);
        ui->comboBox31->setCurrentIndex(2);
        ui->comboBox32->setCurrentIndex(2);
        ui->comboBox33->setCurrentIndex(1);
        ui->comboBox34->setCurrentIndex(1);
        ui->comboBox35->setCurrentIndex(1);

        ui->comboBox01->setEnabled(false);
        ui->comboBox02->setEnabled(false);
        ui->comboBox03->setEnabled(false);
        ui->comboBox04->setEnabled(false);
        ui->comboBox05->setEnabled(false);
        ui->comboBox06->setEnabled(false);
        ui->comboBox07->setEnabled(false);
        ui->comboBox08->setEnabled(false);
        ui->comboBox09->setEnabled(false);
        ui->comboBox10->setEnabled(false);
        ui->comboBox11->setEnabled(false);
        ui->comboBox12->setEnabled(false);
        ui->comboBox13->setEnabled(false);
        ui->comboBox14->setEnabled(false);
        ui->comboBox15->setEnabled(false);
        ui->comboBox16->setEnabled(false);
        ui->comboBox17->setEnabled(false);
        ui->comboBox18->setEnabled(false);
        ui->comboBox19->setEnabled(false);
        ui->comboBox20->setEnabled(false);
        ui->comboBox21->setEnabled(false);
        ui->comboBox22->setEnabled(false);
        ui->comboBox23->setEnabled(false);
        ui->comboBox24->setEnabled(false);
        ui->comboBox25->setEnabled(false);
        ui->comboBox26->setEnabled(false);
        ui->comboBox27->setEnabled(false);
        ui->comboBox28->setEnabled(false);
        ui->comboBox29->setEnabled(false);
        ui->comboBox30->setEnabled(false);
        ui->comboBox31->setEnabled(false);
        ui->comboBox32->setEnabled(false);
        ui->comboBox33->setEnabled(false);
        ui->comboBox34->setEnabled(false);
        ui->comboBox35->setEnabled(false);

    }else{
        ui->comboBox01->setEnabled(true);
        ui->comboBox02->setEnabled(true);
        ui->comboBox03->setEnabled(true);
        ui->comboBox04->setEnabled(true);
        ui->comboBox05->setEnabled(true);
        ui->comboBox06->setEnabled(true);
        ui->comboBox07->setEnabled(true);
        ui->comboBox08->setEnabled(true);
        ui->comboBox09->setEnabled(true);
        ui->comboBox10->setEnabled(true);
        ui->comboBox11->setEnabled(true);
        ui->comboBox12->setEnabled(true);
        ui->comboBox13->setEnabled(true);
        ui->comboBox14->setEnabled(true);
        ui->comboBox15->setEnabled(true);
        ui->comboBox16->setEnabled(true);
        ui->comboBox17->setEnabled(true);
        ui->comboBox18->setEnabled(true);
        ui->comboBox19->setEnabled(true);
        ui->comboBox20->setEnabled(true);
        ui->comboBox21->setEnabled(true);
        ui->comboBox22->setEnabled(true);
        ui->comboBox23->setEnabled(true);
        ui->comboBox24->setEnabled(true);
        ui->comboBox25->setEnabled(true);
        ui->comboBox26->setEnabled(true);
        ui->comboBox27->setEnabled(true);
        ui->comboBox28->setEnabled(true);
        ui->comboBox29->setEnabled(true);
        ui->comboBox30->setEnabled(true);
        ui->comboBox31->setEnabled(true);
        ui->comboBox32->setEnabled(true);
        ui->comboBox33->setEnabled(true);
        ui->comboBox34->setEnabled(true);
        ui->comboBox35->setEnabled(true);




    }
}
