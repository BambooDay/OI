#include <bits/stdc++.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
using namespace std;
	
int main(){
	while(true){
		system("cls");
		cout << "\n\n					欢迎来到 1A2B Game \n\n";
		cout << "游戏规则：\n	系统将随机生成一个 N 进制 M 位 每一位互不相同 的数字 \n        (可能会存在前导零)\n";
		cout << "	您将对这个 M 位的数字做出猜测，每次系统会返回一个形如 \"xAyB\" 的字符串\n";
		cout << "	表示您有 x 个数字是位置与数字均正确，有 y 个数字正确但是位置不正确\n        您需要对系统给出的信息进行分析最终猜出这个数字\n\n";
		cout << "    看懂扣 1 继续\n    没看懂按 0 结束扣眼珠子\n    如果您把 1 扣下来了建议去看看脑子\n";
		int op;
		cin >> op;
		if(!op) return 0;
		system("cls"); 
		cout <<"\n请选择游戏难度：\n    easy: N = 10 M = 2\n    medium: N = 10 M = 4 \n    hard: N = 16 M = 6 \n";
		string s;
		cin >> s;
		int cnt = 0;
		while(s != "easy" && s != "medium" && s !="hard" ){
			if(cnt == 1){
				cout << "您是不是把 1 扣下来了...\n\n";
			}
			if(cnt == 2){
				cout << "您是不是世界上仅存的那个智人...\n\n";
			}
			if(cnt == 3){
				cout << "重大发现：智人还没有灭绝\n\n";
			}
			if(cnt == 4){
				cout << "咱要不还是别玩了吧...\n\n";
			}
			if(cnt == 5){
				cout << "听我一句劝，您去看看脑子\n\n";
			}
			if(cnt == 6){
				cout << "您知道吗？铁离子是无法构成血红蛋白的，构成血红蛋白的是亚铁粒子\n\n";
			}
			if(cnt == 7){
				cout << "算了您开心就好...\n\n";
			}
			cout << "请输入 \"easy\" \"medium\" \"hard\" 之间的字符串:\n";
			cin >> s; 
			cnt++;
		}
		system("cls");	
		bool vis[20] = {0};
		
		if(s == "easy"){
			srand(time(0));
			int _1 = rand() % 10;
			srand(time(0));
			int _2 = rand() % 10;
			vis[_1] = 1;
			while(vis[_2]) _2 = rand() % 10;
			vis[_2] = 1;
			while(true){
				string ans;
				cout << "请输入您的答案：\n";
				cin >> ans;
				if(ans == "BambooDay"){
					ofstream flie("res.txt", ios_base::out);
					flie << _1 << " " << _2 << endl;
					flie.close();
				}
				if(ans.size() != 2){
					cout <<"您看规则了吗？\n\n请重新输入：\n";
					continue;
				}
				int ans1 = ans[0]-'0',ans2 = ans[1]-'0';
				if(ans1 == ans2){
					cout << "请输入各位不同的十进制二位数(可以存在前导零):\n\n";
					continue;
				}
				int x,y;
				x = 0,y = 0;
				if(vis[ans1]){
					if(ans1 == _1) x++;
					else y++;
				}
				if(vis[ans2]){
					if(ans2 == _2) x++;
					else y++;
				}
				if(x == 2){
					cout << "您赢了！！！\n云岳丁真，鉴定为：智力正常\n\n";
					cout << "按 1 继续游戏\n按 0 结束游戏\n";
					cin>> op;
					system("cls");
					if(!op){
						cout << "\n\n\n         再见！祝您生活愉快！\n";
						_sleep(3*1000);
						return 0;
					}
					break;
				}
				cout << x << "A" << y << "B" << endl;
			}
		} 
		if(s == "medium"){
			srand(time(0));
			int _1 = rand() % 10;
			srand(time(0));
			int _2 = rand() % 10;
			srand(time(0));
			int _3 = rand() % 10;
			srand(time(0));
			int _4 = rand() % 10;
			vis[_1] = 1;
			while(vis[_2]) _2 = rand() % 10;
			vis[_2] = 1;
			while(vis[_3]) _3 = rand() % 10;
			vis[_3] = 1;
			while(vis[_4]) _4 = rand() % 10;
			vis[_4] = 1;
			while(true){
				string ans;
				cout << "请输入您的答案：\n";
				cin >> ans;
				if(ans == "BambooDay"){
					ofstream flie("res.txt", ios_base::out);
					flie << _1 << " " << _2  << " " << _3 << " "  << _4 << endl;
					flie.close();
				}
				if(ans.size() != 4){
					cout <<"您看规则了吗？\n\n请重新输入：\n";
					continue;
				}
				int ans1 = ans[0]-'0',ans2 = ans[1]-'0',ans3 = ans[2] - '0',ans4 = ans[3] - '0';
				if( ans1 == ans2 || ans1 == ans3 || ans1 == ans4 || ans2 == ans3 || ans2 == ans4 || ans3 == ans4 ){
					cout << "请输入各位不同的十进制四位数(可以存在前导零):\n\n";
					continue;
				}
				int x,y;
				x = 0,y = 0;
				if(vis[ans1]){
					if(ans1 == _1) x++;
					else y++;
				}
				if(vis[ans2]){
					if(ans2 == _2) x++;
					else y++;
				}
				if(vis[ans3]){
					if(ans3 == _3) x++;
					else y++;
				}
				if(vis[ans4]){
					if(ans4 == _4) x++;
					else y++;
				}
				if(x == 4){
					cout << "您赢了！！！\n欢迎光顾蒟蒻的垃圾箱\n\n";
					cout << "按 1 继续游戏\n按 0 结束游戏\n";
					cin>> op;
					system("cls");
					if(!op){
						cout << "\n\n\n         再见！祝您生活愉快！\n";
						_sleep(3*1000);
						return 0;
					}
					break;
				}
				cout << x << "A" << y << "B" << endl;
			}
		}
		if(s == "hard"){
			cout << "	欢迎挑战最高难度的大佬\n\n";
			_sleep(1*1000);
			cout << "		请在输入时加入前导 0 ，如：1 请打成 01, 13 依旧打成 13\n\n";
			cout << "		祝您游戏愉快\n\n";
			srand(time(0));
			int _1 = rand() % 16;
			srand(time(0));
			int _2 = rand() % 16;
			srand(time(0));
			int _3 = rand() % 16;
			srand(time(0));
			int _4 = rand() % 16;
			srand(time(0));
			int _5 = rand() % 16;
			srand(time(0));
			int _6 = rand() % 16;
			vis[_1] = 1;
			while(vis[_2]) _2 = rand() % 16;
			vis[_2] = 1;
			while(vis[_3]) _3 = rand() % 16;
			vis[_3] = 1;
			while(vis[_4]) _4 = rand() % 16;
			vis[_4] = 1;
			while(vis[_5]) _5 = rand() % 16;
			vis[_5] = 1;
			while(vis[_6]) _6 = rand() % 16;
			vis[_6] = 1;
			while(true){
				string ans;
				cout << "请输入您的答案：\n";
				cin >> ans;
				if(ans == "BambooDay"){
					ofstream flie("res.txt", ios_base::out);
					flie << _1 << " " << _2  << " " << _3 << " "  << _4 << " " << _5 << " " << _6 << endl;
					flie.close();
				}
				if(ans.size() != 12){
					cout <<"大佬您是否没看清规则？\n\n请重新输入：\n";
					continue;
				}
				int ans1 = (ans[0]-'0')* 10 + ans[1] - '0';
				int ans2 = (ans[2]-'0')* 10 + ans[3] - '0';
				int ans3 = (ans[4]-'0')* 10 + ans[5] - '0';
				int ans4 = (ans[6]-'0')* 10 + ans[7] - '0';
				int ans5 = (ans[8]-'0')* 10 + ans[9] - '0';
				int ans6 = (ans[10]-'0')* 10 + ans[11] - '0';
				priority_queue<int> ss;
				ss.push(ans1);
				ss.push(ans2);
				ss.push(ans3);
				ss.push(ans4);
				ss.push(ans5);
				ss.push(ans6);
				if(ss.top() >= 16){
					cout <<"大佬您是否没看清规则？\n每一位都要小于 16 \n请重新输入：\n";
					continue;					
				}
				if(ss.size() != 6){
					cout << "请输入各位不同的十六进制六位数(可以存在前导零):\n";
					cout << "记得输入占位 0 \n\n"; 
					continue;
				}
				int x,y;
				x = 0,y = 0;
				if(vis[ans1]){
					if(ans1 == _1) x++;
					else y++;
				}
				if(vis[ans2]){
					if(ans2 == _2) x++;
					else y++;
				}
				if(vis[ans3]){
					if(ans3 == _3) x++;
					else y++;
				}
				if(vis[ans4]){
					if(ans4 == _4) x++;
					else y++;
				}
				if(vis[ans5]){
					if(ans5 == _5) x++;
					else y++;
				}
				if(vis[ans6]){
					if(ans6 == _6) x++;
					else y++;
				}
				if(x == 6){
					cout << "您赢了！！！\n欢迎光顾蒟蒻的垃圾箱\n\n";
					cout << "按 1 继续游戏\n按 0 结束游戏\n";
					cin>> op;
					system("cls");
					if(!op){
						cout << "\n\n\n         再见！祝您生活愉快！\n";
						_sleep(3*1000);
						return 0;
					}
					break;
				}
				cout << x << "A" << y << "B" << endl;
			}		
		}
	}
	return 0;
}
