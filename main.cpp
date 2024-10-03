#include <iostream>
#include <cstdlib>
#include <ctime>

void guessNumberGame(int& balance) {
	const int minBet = 10; // 猜数字游戏的最低下注金额
	int bet, guess, number;
	
	std::cout << "欢迎来到猜数字赌博游戏！中奖概率设为 12.5%！\n";
	
	while (true) {
		std::cout << "你的当前余额是：" << balance << "\n";
		if (balance < minBet) {
			std::cout << "余额不足，无法继续游戏。请充值或贷款！\n";
			break;
		}
		
		std::cout << "请输入下注金额（至少 $10）：";
		std::cin >> bet;
		
		if (bet < minBet) {
			std::cout << "下注金额不能少于 $10，请重新输入。\n";
			continue;
		}
		
		number = rand() % 8 + 1; // 生成1到8之间的随机数
		
		bool guessedCorrectly = false; // 标记是否猜中
		for (int attempts = 0; attempts < 3; ++attempts) {
			std::cout << "请猜一个数字（1-8），你还有 " << (3 - attempts) << " 次机会：";
			std::cin >> guess;
			
			// 确保玩家的猜测在有效范围内
			if (guess < 1 || guess > 8) {
				std::cout << "请输入有效数字（1到8之间）。\n";
				--attempts; // 不消耗机会
				continue;
			}
			
			if (guess == number) {
				guessedCorrectly = true; // 猜中
				balance += bet * 2; // 奖金翻倍
				std::cout << "恭喜你！你猜对了！你赢得了 $" << bet * 2 << "。\n";
				break; // 猜中后退出循环
			} else {
				std::cout << "很遗憾，你猜错了。\n";
				
				// 询问玩家是否放弃奖金再猜一次
				if (attempts < 2) { // 除了最后一次猜测
					char choice;
					std::cout << "你想放弃当前奖金再猜一次吗？（y/n）：";
					std::cin >> choice;
					if (choice == 'y' || choice == 'Y') {
						std::cout << "你放弃了当前奖金，进行下一次猜测。\n";
						continue; // 不扣除下注金额，继续下一次猜测
					}
				}
			}
		}
		
		if (!guessedCorrectly) {
			balance -= bet; // 所有机会用完且未猜中，扣除下注金额
			std::cout << "你没有猜中，失去了 $" << bet << "。\n";
		}
		
		if (balance >= 50000) { // 检查是否达到赌场价值
			std::cout << "恭喜你！你已经积累了足够的资金买下赌场！游戏通过！\n";
			break;
		}
		
		if (balance <= 0) {
			std::cout << "你的余额为0，游戏结束！\n";
			break;
		}
	}
	
	std::cout << "感谢游玩，你的最终余额是：" << balance << "\n";
}

void rockPaperScissorsGame(int& balance) {
	std::string choices[3] = {"石头", "剪刀", "布"};
	int minBet = 6; // 石头剪刀布游戏的最低下注金额
	
	std::cout << "欢迎来到石头剪刀布赌博游戏！\n";
	
	for (int gameRound = 0; gameRound < 2; ++gameRound) { // 玩家有两次机会
		std::cout << "你的当前余额是：" << balance << "\n";
		if (balance < minBet) {
			std::cout << "余额不足，无法继续游戏。请充值或贷款！\n";
			break;
		}
		
		int bet;
		std::cout << "请输入下注金额（固定为 $6）：";
		std::cin >> bet;
		
		if (bet < minBet) {
			std::cout << "下注金额不能少于 $6，请重新输入。\n";
			continue;
		}
		
		int playerChoice;
		std::cout << "请选择：\n";
		std::cout << "0 - 石头\n";
		std::cout << "1 - 剪刀\n";
		std::cout << "2 - 布\n";
		std::cout << "输入你的选择（0-2）：";
		std::cin >> playerChoice;
		
		// 检查输入有效性
		if (playerChoice < 0 || playerChoice > 2) {
			std::cout << "无效选择，请重新输入。\n";
			continue;
		}
		
		int computerChoice = rand() % 3; // 生成计算机的选择
		std::cout << "你选择了：" << choices[playerChoice] << "\n";
		std::cout << "计算机选择了：" << choices[computerChoice] << "\n";
		
		// 判断胜负
		if (playerChoice == computerChoice) {
			std::cout << "平局！\n";
			std::cout << "你的下注金额保持不变。\n";
		} else if ((playerChoice == 0 && computerChoice == 1) || 
			(playerChoice == 1 && computerChoice == 2) || 
			(playerChoice == 2 && computerChoice == 0)) {
			std::cout << "你赢了！\n";
			balance += bet; // 赢得下注金额
			std::cout << "你获得了 $" << bet << "。\n";
		} else {
			std::cout << "你输了！\n";
			balance -= bet; // 失去下注金额
			std::cout << "你失去了 $" << bet << "。\n";
		}
		
		if (balance >= 50000) { // 检查是否达到赌场价值
			std::cout << "恭喜你！你已经积累了足够的资金买下赌场！游戏通过！\n";
			break;
		}
		
		if (balance <= 0) {
			std::cout << "你的余额为0，游戏结束！\n";
			break;
		}
	}
	
	std::cout << "感谢游玩，你的最终余额是：" << balance << "\n";
}

void loanSystem(int& balance, int& loan) {
	int loanAmount;
	std::cout << "你的当前余额是：" << balance << "\n";
	std::cout << "你可以贷款的金额：50、100、300\n";
	std::cout << "请输入贷款金额：";
	std::cin >> loanAmount;
	
	if (loanAmount == 50 || loanAmount == 100 || loanAmount == 300) {
		loan += loanAmount; // 更新贷款金额
		balance += loanAmount; // 增加余额
		std::cout << "你已成功贷款 $" << loanAmount << "。\n";
	} else {
		std::cout << "无效的贷款金额，请重新输入。\n";
	}
}

void tempJob(int& balance) {
	// 30% 概率找不到工作
	if (rand() % 100 < 30) {
		std::cout << "很遗憾，你没有找到工作。\n";
	} else {
		balance += 70; // 找到工作，增加余额
		std::cout << "恭喜你！你找到工作，获得了 $70。\n";
	}
}

int main() {
	srand(static_cast<unsigned int>(time(0))); // 随机数种子
	int gameChoice;
	int balance = 100; // 玩家初始余额
	int loan = 0; // 玩家贷款金额
	
	std::cout << "欢迎来到赌场！你可以选择 666 直接买下赌场（价值 50000 元）！\n";
	std::cout << "或选择 3 来贷款。\n";
	std::cout << "或选择 4 来打临时工。\n";
	std::cout << "之后你可以选择你想玩的游戏：\n";
	std::cout << "1 - 猜数字赌博游戏（下注 $10）\n";
	std::cout << "2 - 石头剪刀布赌博游戏（下注 $6）\n";
	std::cout << "输入你的选择（1、2、3、4 或 666）：";
	std::cin >> gameChoice;
	
	if (gameChoice == 3) {
		loanSystem(balance, loan); // 贷款
	} else if (gameChoice == 4) {
		tempJob(balance); // 打临时工
	} else if (gameChoice == 666) {
		if (balance >= 50000) {
			std::cout << "恭喜你！你已经成功买下赌场！游戏通过！\n";
		} else {
			std::cout << "你没有足够的资金来买下赌场。\n";
		}
	} else {
		switch (gameChoice) {
		case 1:
			guessNumberGame(balance);
			break;
		case 2:
			rockPaperScissorsGame(balance);
			break;
		default:
			std::cout << "无效选择。\n";
			break;
		}
	}
	
	return 0;
}
