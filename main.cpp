#include <iostream>
#include <cstdlib>
#include <ctime>

void guessNumberGame(int& balance) {
	const int minBet = 10; // 猜数字游戏的最低下注金额
	int bet, guess, number;
	
	std::cout << "欢迎来到猜数字赌博游戏！中奖概率设为 12.5%！\n\n";
	
	while (true) {
		std::cout << "你的当前余额是：" << balance << "\n";
		if (balance < minBet) {
			std::cout << "余额不足，无法继续游戏。请充值！\n\n";
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
			}
		}
		
		if (!guessedCorrectly) {
			balance -= bet; // 所有机会用完且未猜中，扣除下注金额
			std::cout << "你没有猜中，失去了 $" << bet << "。\n";
		}
		
		if (balance <= 0) {
			std::cout << "你的余额为0，游戏结束！\n";
			break;
		}
		
		// 在游戏结束后询问是否继续猜测
		char choice;
		std::cout << "你想继续猜测吗？（y/n）：";
		std::cin >> choice;
		if (choice == 'n' || choice == 'N') {
			break; // 退出猜数字游戏
		}
	}
	
	std::cout << "感谢游玩，你的最终余额是：" << balance << "\n\n";
}

void rockPaperScissorsGame(int& balance) {
	std::string choices[3] = {"石头", "剪刀", "布"};
	int minBet = 6; // 石头剪刀布游戏的最低下注金额
	
	std::cout << "欢迎来到石头剪刀布赌博游戏！\n\n";
	
	for (int gameRound = 0; gameRound < 2; ++gameRound) { // 玩家有两次机会
		std::cout << "你的当前余额是：" << balance << "\n";
		if (balance < minBet) {
			std::cout << "余额不足，无法继续游戏。请充值或贷款！\n\n";
			break;
		}
		
		int bet;
		std::cout << "请输入下注金额（固定为 $6）：";
		std::cin >> bet;
		
		if (bet < minBet) {
			std::cout << "下注金额不能少于 $6，请重新输入。\n\n";
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
			std::cout << "无效选择，请重新输入。\n\n";
			continue;
		}
		
		int computerChoice = rand() % 3; // 生成计算机的选择
		std::cout << "你选择了：" << choices[playerChoice] << "\n";
		std::cout << "计算机选择了：" << choices[computerChoice] << "\n";
		
		// 判断胜负
		if (playerChoice == computerChoice) {
			std::cout << "平局！\n";
			std::cout << "你的下注金额保持不变。\n\n";
		} else if ((playerChoice == 0 && computerChoice == 1) || 
			(playerChoice == 1 && computerChoice == 2) || 
			(playerChoice == 2 && computerChoice == 0)) {
			std::cout << "你赢了！\n";
			balance += bet; // 赢得下注金额
			std::cout << "你获得了 $" << bet << "。\n\n";
		} else {
			std::cout << "你输了！\n";
			balance -= bet; // 失去下注金额
			std::cout << "你失去了 $" << bet << "。\n\n";
		}
		
		// 在游戏结束后询问是否继续猜测
		char choice;
		std::cout << "你想继续猜测吗？（y/n）：";
		std::cin >> choice;
		if (choice == 'n' || choice == 'N') {
			break; // 退出猜数字游戏
		}
		
		if (balance >= 50000) { // 检查是否达到赌场价值
			std::cout << "恭喜你！你已经积累了足够的资金买下赌场！游戏通过！\n\n";
			break;
		}
		
		if (balance <= 0) {
			std::cout << "你的余额为0，游戏结束！\n\n";
			break;
		}
	}
	
	std::cout << "感谢游玩，你的最终余额是：" << balance << "\n\n";
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
		std::cout << "你已成功贷款 $" << loanAmount << "。\n\n";
	} else {
		std::cout << "无效的贷款金额，请重新输入。\n\n";
	}
}

void payLoan(int& balance, int& loan) {
	if (loan == 0) {
		std::cout << "你没有任何贷款。\n\n";
		return;
	}
	
	int repaymentAmount;
	std::cout << "你的当前余额是：" << balance << "\n";
	std::cout << "你当前的贷款余额是：" << loan << "\n";
	std::cout << "请输入还款金额：";
	std::cin >> repaymentAmount;
	
	if (repaymentAmount > balance) {
		std::cout << "余额不足，无法还款。\n\n";
	} else if (repaymentAmount > loan) {
		std::cout << "还款金额不能超过当前贷款余额。\n\n";
	} else {
		loan -= repaymentAmount; // 更新贷款余额
		balance -= repaymentAmount; // 扣除余额
		std::cout << "你已成功还款 $" << repaymentAmount << "。\n";
		std::cout << "当前贷款余额为：" << loan << "\n\n";
	}
}

void tempJob(int& balance) {
	// 30% 概率找不到工作
	if (rand() % 100 < 30) {
		std::cout << "很遗憾，你没有找到工作。\n\n";
	} else {
		balance += 70; // 找到工作，增加余额
		std::cout << "恭喜你！你找到工作，获得了 $70。\n\n";
	}
}

int main() {
	srand(static_cast<unsigned int>(time(0))); // 随机数种子
	int gameChoice;
	int balance = 100; // 玩家初始余额
	int loan = 0; // 玩家贷款金额
	
	while (true) { // 循环询问用户的选择
		std::cout << "欢迎来到赌场！你可以选择 666 直接买下赌场（价值 50000 元）！\n";
		std::cout << "或选择 3 来贷款。\n";
		std::cout << "或选择 4 来打临时工。\n";
		std::cout << "或选择 5 来还贷款。\n"; // 添加还贷款选项
		std::cout << "之后你可以选择你想玩的游戏：\n";
		std::cout << "1 - 猜数字赌博游戏（下注 $10）\n";
		std::cout << "2 - 石头剪刀布赌博游戏（下注 $6）\n";
		std::cout << "输入你的选择（1、2、3、4、5 或 666）：";
		std::cin >> gameChoice;
		
		if (gameChoice == 666) {
			if (balance >= 50000) {
				std::cout << "恭喜你！你成功买下赌场！\n\n";
				break; // 买下赌场，结束游戏
			} else {
				std::cout << "你没有足够的资金买下赌场！\n\n"; // 没有足够资金
				continue; // 继续询问
			}
		} else if (gameChoice == 3) {
			loanSystem(balance, loan);
		} else if (gameChoice == 4) {
			tempJob(balance);
		} else if (gameChoice == 5) {
			payLoan(balance, loan); // 还贷款
		} else if (gameChoice == 1) {
			guessNumberGame(balance);
		} else if (gameChoice == 2) {
			rockPaperScissorsGame(balance);
		} else {
			std::cout << "无效选择，请重新输入。\n\n";
			continue; // 继续询问
		}
		
		if (balance <= 0) {
			std::cout << "你的余额为0，游戏结束！\n\n";
			break; // 余额为零，结束游戏
		}
	}
	
	std::cout << "感谢游玩，你的最终余额是：" << balance << "\n\n";
	return 0;
}
