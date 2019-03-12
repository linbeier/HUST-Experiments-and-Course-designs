#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    timer=new QTimer(this);
    getstart();

    connect(timer,SIGNAL(timeout()),this,SLOT(cpuupdate()));
    connect(timer,SIGNAL(timeout()),this,SLOT(memupdate()));
    connect(timer,SIGNAL(timeout()),this,SLOT(pidupdate()));
    connect(timer,SIGNAL(timeout()),this,SLOT(graph()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getstart(){
    tempfile.setFileName("/proc/version");
    if(!tempfile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,tr("warning"),tr("sys info open fail!"),QMessageBox::Yes);
        return -1;
    }
    QString sysinfo,typeinfo,versioninfo,gccinfo;
    sysinfo=tempfile.readLine();
    typeinfo=sysinfo.mid(0,5);
    versioninfo=sysinfo.mid(6,40);
    gccinfo=sysinfo.mid(60,50);
    ui->label_12->setText(typeinfo);
    ui->label_13->setText(versioninfo);
    ui->label_14->setText(gccinfo);
    tempfile.close();
    tempfile2.setFileName("/proc/cpuinfo");
    if(!tempfile2.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,tr("warning"),tr("cpu info open fail!"),QMessageBox::Yes);
        return -1;
    }

    QStringList cpuinfovalue;
    QString pattern("(\\w+)(\\s*)(\\w+)(\\s*)(\\:)(\\s*)(\\w+)");
    QRegExp rx(pattern);
    int pos;
    while(1)
    {
        tempstr=tempfile2.readLine();
        if(tempstr==NULL)break;
        if(tempstr.indexOf("model name")!=-1)
        {
            pos=tempstr.indexOf(rx);
            pos+=13;
            QString cpuname=tempstr.mid(pos,tempstr.length()-13);

            cpuinfovalue.append(cpuname);

        }
        else if(tempstr.indexOf("cpu cores")!=-1)
        {
            pos=tempstr.indexOf(rx);
            //qDebug()<<pos;
            //qDebug()<<rx.cap(0);

            cpuinfovalue.append(rx.cap(7));
        }
        else if(tempstr.indexOf("cache size")!=-1)
        {
            pos=tempstr.indexOf(rx);

            cpuinfovalue.append(rx.cap(7));
        }
        else if(tempstr.indexOf("address sizes")!=-1)
        {
            pos=tempstr.indexOf(rx);
            pos+=16;
            QString cpuname=tempstr.mid(pos,tempstr.length()-16);

            cpuinfovalue.append(cpuname);
        }
    }

    ui->label_6->setText(cpuinfovalue.at(0));
    ui->label_7->setText(cpuinfovalue.at(2));
    ui->label_8->setText(cpuinfovalue.at(1));
    ui->label_9->setText(cpuinfovalue.at(3));
    tempfile2.close();
    return 1;
}

void MainWindow::cpuupdate(){

    int times=2;
    int pos,total[2],used[2],left[2];
    int user,nice,sys,idle,iowait;
    QString pattern("(\\w+)(\\s+)((([0-9]*)(\\s+)){5})");
    QRegExp rx(pattern);
    QFile tempfile3;
    QStringList templist;
    while(times)
    {
        tempfile3.setFileName("/proc/stat");
        if(tempfile3.open(QIODevice::ReadOnly)==-1)
        {
            return;
        }
        tempstr=tempfile3.readLine();
        pos=tempstr.indexOf(rx);
        //qDebug()<<rx.cap(0);
        tempstr=rx.cap(3);
        templist=tempstr.split(" ");
        user=templist[0].toInt();
        nice=templist[1].toInt();
        sys=templist[2].toInt();
        idle=templist[3].toInt();
        iowait=templist[4].toInt();
        total[2-times]=user+nice+sys+idle+iowait;
        used[2-times]=user+nice+sys+iowait;
        left[2-times]=idle;
        times--;
        tempfile3.close();
        QTime dieTime=QTime::currentTime().addMSecs(500);
        while(QTime::currentTime()<dieTime)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents,500);
        }
    }

    cpucount++;
    cputime.enqueue(cpucount);
    if(cputime.size()>20)
    {
        cputime.dequeue();
        changerangeflag=1;
    }
    double result;
    result=((used[1]-used[0])*100/(total[1]-total[0]));

    double trash;
    cpupoint.enqueue(result);
    if(cpupoint.size()>20)
    {
        trash=cpupoint.dequeue();
    }
    ui->progressBar->setValue((int)result);
    QString str;
    str="total:"+QString::number(total[1]-total[0])+"msc";
    ui->cpu_total->setText(str);
    str="used:"+QString::number(used[1]-used[0])+"msc";
    ui->cpu_used->setText(str);
    str="left:"+QString::number(left[1]-left[0])+"msc";
    ui->cpu_left->setText(str);

}

void MainWindow::memupdate(){
    tempfile.setFileName("/proc/meminfo");
    if(tempfile.open(QIODevice::ReadOnly)==-1)
    {
        return;
    }
    int memtotal,memfree,swaptotal,swapfree;
    double memusedrate,swapusedrate;
    QString pattern("(\\w+)(\\:)(\\s*)([0-9]+)");
    QRegExp rx(pattern);
    QStringList list;
    while(1)
    {
        tempstr=tempfile.readLine();
        if(tempstr==NULL)break;
        if(tempstr.indexOf("MemTotal")!=-1)
        {
            tempstr.indexOf(rx);
            list.append(rx.cap(4));
        }
        else if(tempstr.indexOf("MemAvailable")!=-1)
        {
            tempstr.indexOf(rx);
            list.append(rx.cap(4));
            // qDebug()<<rx.cap(0);
        }
        else if(tempstr.indexOf("SwapTotal")!=-1)
        {
            tempstr.indexOf(rx);
            list.append(rx.cap(4));
             //qDebug()<<rx.cap(0);
        }
        else if(tempstr.indexOf("SwapFree")!=-1)
        {
            tempstr.indexOf(rx);
            list.append(rx.cap(4));
             //qDebug()<<rx.cap(0);

        }
    }
    QString str;
    memtotal=list[0].toInt();
    memfree=list[1].toInt();
    swaptotal=list[2].toInt();
    swapfree=list[3].toInt();
    memusedrate=((double)(memtotal-memfree)/(double)memtotal)*100;
    swapusedrate=((double)(swaptotal-swapfree)/(double)swaptotal)*100;
    ui->progressBar_2->setValue(memusedrate);
    ui->progressBar_3->setValue(swapusedrate);
    str="total"+QString::number(memtotal/1024)+"M";
    ui->memory_total->setText(str);
    str="used"+QString::number((memtotal-memfree)/1024)+"M";
    ui->memory_used->setText(str);
    str="left"+QString::number(memfree/1024)+"M";
    ui->memory_left->setText(str);

    str="total"+QString::number(swaptotal/1024)+"M";
    ui->swap_total->setText(str);
    str="used"+QString::number((swaptotal-swapfree)/1024)+"M";
    ui->swap_used->setText(str);
    str="left"+QString::number(swapfree/1024)+"M";
    ui->swap_left->setText(str);
    tempfile.close();
}

void MainWindow::pidupdate(){
    ui->listWidget->clear();
    QListWidgetItem *title= new QListWidgetItem("PID\t"+QString::fromUtf8("name")+"\t"+QString::fromUtf8("state")
                                                +"\t"+QString::fromUtf8("size"),ui->listWidget);
    DIR *dir;
    struct dirent *ptr;
    if(!(dir=opendir("/proc")))
        return;

    while(ptr=readdir(dir))
    {
        if(ptr->d_name[0]>'0'&&ptr->d_name[0]<='9')
            pidread(ptr->d_name);
    }
    QString label;
    label="sleeping:"+QString::number(sleepcount);
    ui->label_20->setText(label);
    label="running:"+QString::number(runcount);
    ui->label_21->setText(label);
    label="stop:"+QString::number(stopcount);
    ui->label_22->setText(label);
    sleepcount=runcount=stopcount=0;
}

void MainWindow::pidread(char *path){
    QString str,temp(path);
    int sleepnum=0,activenum=0,total=0;
    str="/proc/"+temp+"/status";
    tempfile.setFileName(str);
    if(tempfile.open(QIODevice::ReadOnly)==-1)
    {
        return;
    }
    QString pattern("(\\w+)(\\:)(\\s*)(\\w+)");
    int i;
    QRegExp rx(pattern);
    QStringList list,relist;
    list.append("Pid");
    list.append("Name");
    list.append("State");
    list.append("VmSize");
    QString name,pid,state,size;
    while(1)
    {
        str=tempfile.readLine();
        if(str==NULL)break;
        if(str.indexOf(rx)!=-1)
        {
            for(i=0;i<4;i++)
            {
                if(rx.cap(1)==list.at(i))
                {
                    //qDebug()<<list.at(i)<<rx.cap(0);
                    relist.insert(i,rx.cap(4));
                    if(i==2)
                    {
                        if(rx.cap(4)=="S")
                            sleepcount++;
                        else if(rx.cap(4)=="R")
                            runcount++;
                        else if (rx.cap(4)=="T")
                            stopcount++;
                    }

                 }
             }

        }

    }
    if(relist.size()==4)
    {
        pid=relist.at(0);
        name=relist.at(1);
        state=relist.at(2);
        size=relist.at(3);
        QListWidgetItem *item=new QListWidgetItem(pid+"\t"+name+"\t"+state+"\t"+size,ui->listWidget);
    }
    tempfile.close();
}

void MainWindow::graph(){
    graphshow(ui->widget);
}

void MainWindow::graphshow(QCustomPlot *customplot){
    QVector<double> time,point;
    int i;
    for(i=0;i<cputime.size();i++)
    {
        time.insert(i,cputime.at(i));
        point.insert(i,cpupoint.at(i));
    }
    if(changerangeflag==1)
    {
        customplot->xAxis->setRange(cputime.at(0),cputime.at(19));
    }
    else
    {
        customplot->xAxis->setRange(0,20);
    }
    customplot->addGraph();
    customplot->graph(0)->setPen(QPen(Qt::red));
    customplot->graph(0)->setData(time,point);
    //customplot->xAxis->setLabel("t");
    customplot->yAxis->setLabel("percent");
    //customplot->xAxis->setRange(0,40);
    customplot->yAxis->setRange(0,100);
    customplot->replot();

}

void MainWindow::on_pushButton_3_clicked()
{

       system("kill " + pro.toLatin1());
       QMessageBox::warning(this, tr("kill"), QString::fromUtf8("process has been killed"), QMessageBox::Yes);
}

void MainWindow::on_pushButton_clicked()
{
    system("hault");
}

void MainWindow::on_pushButton_2_clicked()
{
    system("reboot");
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    //获得进程号
       item = ui->listWidget->currentItem();
       pro = item->text();
       pro = pro.section("\t", 0, 0);
       tempfile.setFileName("/proc/"+pro+"/status");
       tempfile.open(QIODevice::ReadOnly);
       QString str=tempfile.readAll();
       QMessageBox msg;
       msg.move(1200,0);
       msg.about(0,tr("about "+pro.toLatin1()),str);

       tempfile.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    pidupdate();
}
