#include<bits/stdc++.h>
using namespace std;
struct node{
    //聊天内容
    string __Message;
    //当时情绪值
    int __Emotion;
    //Unix时间戳
    int __TimeStamp;
    //类型:
    //1:问候语
    int __Type;
    
}__Dialogue[32767];
/*__Emotion情绪值,__Idenity最后的聊天ID*/int __Emotion,__Idenity=0;
/*AI对你的称呼*/string __Nickname="博士";
/*本地时间，考虑到调试问题，在AI运行时不会更新*/struct tm *localtime(const time_t * calptr);
void __AIOut(int __TempType);
void __AIOut(int __TempType,string __TempMessage);
void __AIOut(int __TempType){
    /*输出信息缓冲区*/string __MsgBuffer[255];
    /*缓冲区进位索引*/int __BufferHead=0;
    if(__TempType==1){
        if(__Emotion<=95){
            __MsgBuffer[__BufferHead]=__Nickname+",";
            __BufferHead++;
            __MsgBuffer[__BufferHead]="您好!";
        }
    }
    for(int __TmpInteger0=0;__TmpInteger0<=__BufferHead;__TmpInteger0++){
        cout<<__MsgBuffer[__TmpInteger0];
    }
}
void __AIExecute(string __TempMessage){
    if(__TempMessage.find("早上")!=string::npos||
       __TempMessage.find("上午")!=string::npos||
       __TempMessage.find("中午")!=string::npos||
       __TempMessage.find("下午")!=string::npos||
       __TempMessage.find("晚上")!=string::npos||
       __TempMessage.find("你")!=string::npos){
        if(__TempMessage.find("好")!=string::npos){
            __Dialogue[__Idenity].__Message=__TempMessage;
            __Dialogue[__Idenity].__Emotion=__Emotion;
            __Dialogue[__Idenity].__TimeStamp=(unsigned)time(NULL);
            __Dialogue[__Idenity].__Type=1;
            __AIOut(1);
        }
    }
    else if(__TempMessage.find("天气")!=string::npos||
            __TempMessage.find("weather")!=string::npos)
    {
        cout<<"为您跳转到天气页"<<endl;
        system("start http://www.weather.com.cn/");
    }
    else
    {
        cout<<"嘤嘤嘤……还在学习中"<<endl;
    }
    
}
int main(){
    string __TempMessage;
    while(1)
    {
    	cin>>__TempMessage;
    	srand((unsigned)time(NULL));
    	__Emotion=rand()%9+90;
    	__AIExecute(__TempMessage);
	}
}
