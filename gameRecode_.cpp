#include <bits/stdc++.h>
using namespace std;
int money=100;//玩家钱数 
int gamechose;//选择玩法 

int Check()//检查输入是否为数字 
{
    int choice;
    while(true)
    {
        cin>>choice;
        //检查输入是否有效
        if(cin.fail())
        {
            cin.clear();//清除错误标志
            cin.ignore(numeric_limits<streamsize>::max(),'\n');//丢弃无效输入
            cout<<"输入无效，请输入数字！"<<endl;
            continue;//重新开始循环
        }
        return choice;//有效选择
    }
}

int xianshi()//主页面
{
    cout<<"1 - 猜数字赌博游戏（下注 \$10）\n";
    cout<<"2 - 石头剪刀布赌博游戏（下注 \$6）\n";
    cout<<"输入你的选择（1、2）：";
    return Check();//直接返回 Check() 的结果
} 
//———————————————————————————————————————————— 
void guessNumberGame() 
{
	string a;//返回主页 
	int number,guess;
    system("cls");
    int NumberMoney;
    const int minBet=10;//下赌最低金额 
    cout<<"欢迎来到猜数字赌博游戏！中奖概率设为 12.5%！\n";
    while(true)
    {
        cout<<"你的当前余额是：" <<money<<"\n";
        if(money<minBet)
        {
            cout<<"余额不足，无法继续游戏。输入back返回主页面进行充值或贷款！\n";
            cin>>a;
            if(a=="back")
            {
                system("cls"); 
                xianshi();
            }
            else
            	continue;
        }

        cout<<"请输入下注金额（至少 \$10）：";
        cin>>NumberMoney;//要赌的钱
        if(NumberMoney<minBet)
        {
            cout<<"下注金额不能少于 $10，请重新输入。\n";
            continue;
        }
        //下注逻辑
        number=rand()%8+1;//生成1到8之间的随机数 
        bool GuessSuccess=false;//标记是否猜中
        for(int i=0;i<3;i++)
        {
        	cout<<"请猜一个数字（1-8），你还有 "<<3-i<<" 次机会：";
        	Check();
			if(guess==number)
			{
				GuessSuccess=true;//猜中
				money+=NumberMoney*2;//奖金翻倍
				cout<<"恭喜你！你猜对了！你赢得了 $"<<NumberMoney*2<<"。\n";
				break;//猜中后退出循环
			}
			else
				cout<<"很遗憾，你猜错了。\n";
		}
		if(!GuessSuccess)
		{
			money-=NumberMoney;//所有机会用完且未猜中，扣除下注金额
			std::cout<<"你没有猜中，失去了 $"<<NumberMoney<<"。\n";
		} 
		cout<<"输入任意返回主页面\n";
		cin>>a; 
        if(a=="j"){system("cls"); xianshi();}
        else{system("cls"); xianshi();}
    }
}
//———————————————————————————————————————————— 
void sjb()
{
	string a;//返回主页 
	system("cls");
	int NumberMoney;
	string s[3]={"石头","剪刀","布"};//三个选择
	int minBet=6;//石头剪刀布游戏的最低下注金额 
	cout<<"欢迎来到石头剪刀布赌博游戏！\n";
	for(int i=0;i<2;i++)
	{
		cout<<"你的当前余额是："<<money<<"\n";
		if(money<minBet)
        {
            cout<<"余额不足，无法继续游戏。输入back返回主页面进行充值或贷款！\n";
            cin>>a;
            if(a=="back")
            {
                system("cls"); 
                xianshi();
            }
            else
            	continue;
        }
        cout<<"请输入下注金额（至少 $6）：";
        Check();
        if(NumberMoney<minBet)
        {
            cout<<"下注金额不能少于 $6，请重新输入。\n";
            continue;
        }
		int PlayerChose;
		cout<<"请选择：\n";
		cout<<"0 - 石头\n";
		cout<<"1 - 剪刀\n";
		cout<<"2 - 布\n";
		cout<<"输入你的选择（0-2）：";
		if(PlayerChose<0 || PlayerChose>2)
		{
			cout<<"无效选择，请重新输入。\n";
			continue;
		}
		Check();
		int ComputerChose=rand()%3;
		cout<<"你选择了："<<s[PlayerChose]<<"\n";
		cout<<"计算机选择了："<<s[ComputerChose]<<"\n";
		//判断逻辑
		if(PlayerChose==ComputerChose)
		{
			cout<<"平局！\n";
			cout<<"你的下注金额保持不变。\n";
		}
		else if((PlayerChose==0 && ComputerChose==1) || 
		        (PlayerChose==1 && ComputerChose==2) || 
				(PlayerChose==2 && ComputerChose==0)) 
		{
			cout<<"你赢了！\n";
			money+=NumberMoney; // 赢得下注金额
			cout<<"你获得了 $"<<NumberMoney<<"。\n";
		}
		else
		{
			cout<<"你输了！\n";
			money-=NumberMoney;//失去下注金额
			cout<<"你失去了 $"<<NumberMoney<<"。\n";
		}
	}
}

int main()
{
    while(true)
    {
        gamechose=xianshi(); //取用户选择并赋值
        // 据不同选择调用相应的函数
        if(gamechose==1)
        {
            guessNumberGame();
        }
        else if(gamechose==2)
        {
            sjb();
        }
    }

    return 0;
}
