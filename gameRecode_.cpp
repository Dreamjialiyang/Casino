#include <bits/stdc++.h>
using namespace std;
int money=100;//���Ǯ�� 
int gamechose;//ѡ���淨 

int Check()//��������Ƿ�Ϊ���� 
{
    int choice;
    while(true)
    {
        cin>>choice;
        //��������Ƿ���Ч
        if(cin.fail())
        {
            cin.clear();//��������־
            cin.ignore(numeric_limits<streamsize>::max(),'\n');//������Ч����
            cout<<"������Ч�����������֣�"<<endl;
            continue;//���¿�ʼѭ��
        }
        return choice;//��Чѡ��
    }
}

int xianshi()//��ҳ��
{
    cout<<"1 - �����ֶĲ���Ϸ����ע \$10��\n";
    cout<<"2 - ʯͷ�������Ĳ���Ϸ����ע \$6��\n";
    cout<<"�������ѡ��1��2��3��4 �� 666����";
    return Check();//ֱ�ӷ��� Check() �Ľ��
} 

void guessNumberGame()
{
	int number,guess;
    system("cls");
    int NumberMoney;
    const int minBet=10;//�¶���ͽ�� 
    cout<<"��ӭ���������ֶĲ���Ϸ���н�������Ϊ 12.5%��\n";

    while(true)
    {
        cout<<"��ĵ�ǰ����ǣ�" <<money<<"\n";
        if(money<minBet)
        {
            string a;
            cout<<"���㣬�޷�������Ϸ������back������ҳ����г�ֵ����\n";
            cin>>a;
            if(a=="back")
            {
                system("cls"); 
                xianshi();
            }
        }

        cout<<"��������ע������ \$10����";
        cin>>NumberMoney;//Ҫ�ĵ�Ǯ
        if(NumberMoney<minBet)
        {
            cout<<"��ע�������� \$10�����������롣\n";
            continue;
        }
        //��ע�߼�
        number=rand()%8+1;//����1��8֮�������� 
        bool GuessSuccess=false;//����Ƿ����
        for(int i=1;i<=3;i++)
        {
        	cout<<"���һ�����֣�1-8�����㻹�� "<<3-i<<" �λ��᣺";
        	cin>>guess;
        	Check();
			if(guess==number)
			{
				GuessSuccess=true;//����
				money+=bet*2;//���𷭱�
				cout<<"��ϲ�㣡��¶��ˣ���Ӯ���� $"<<bet*2<<"��\n";
				break;//���к��˳�ѭ��
			}
			else
				cout<<"���ź�����´��ˡ�\n";
 
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
        gamechose=xianshi(); //ȡ�û�ѡ�񲢸�ֵ
        // �ݲ�ͬѡ�������Ӧ�ĺ���
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

