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
    cout<<"输入你的选择（1、2、3、4 或 666）：";
    return Check();//直接返回 Check() 的结果
} 

void guessNumberGame()
{
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
            string a;
            cout<<"余额不足，无法继续游戏。输入back返回主页面进行充值或贷款！\n";
            cin>>a;
            if(a=="back")
            {
                system("cls"); 
                xianshi();
            }
        }

        cout<<"请输入下注金额（至少 \$10）：";
        cin>>NumberMoney;//要赌的钱
        if(NumberMoney<minBet)
        {
            cout<<"下注金额不能少于 \$10，请重新输入。\n";
            continue;
        }
        //下注逻辑
        number=rand()%8+1;//生成1到8之间的随机数 
        bool GuessSuccess=false;//标记是否猜中
        for(int i=1;i<=3;i++)
        {
        	cout<<"请猜一个数字（1-8），你还有 "<<3-i<<" 次机会：";
        	cin>>guess;
        	Check();
			if(guess==number)
			{
				GuessSuccess=true;//猜中
				money+=bet*2;//奖金翻倍
				cout<<"恭喜你！你猜对了！你赢得了 $"<<bet*2<<"。\n";
				break;//猜中后退出循环
			}
			else
				cout<<"很遗憾，你猜错了。\n";
 
		}
    }
}

void sjb()
{
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

