#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class baseball_game {
public:
	int random, num, num_cin[3], rand_cin[3], strike = 0, ball = 0, out = 0, check = 0, re, num_try = 0;
	void make_random() {
		while (1) {
			random = rand() % 999 + 100;

			for (int a = 0; a <= 2; a++) {
				rand_cin[2 - a] = random % 10;
				random /= 10;
			}

			for (int a = 0; a <= 1; a++) {

				for (int b = 1; b <= 2; b++) {
					if (a + b < 3) {

						if (rand_cin[a] == rand_cin[a + b])
							break;
					}
					else {
						check = 1;
					}
				}

			}
			if (check == 1) {
				check = 0;
				break;
			}
		}

	}
	bool re_start() {
		if (strike == 3)
		{
			cout << "\n*************승리하셨습니다!!*************\n" << endl;
			cout << "" << num_try << "번 만에 맞추셨습니다!" << endl;
			cout << "종료하실려면 1을 눌러주세요!(다시하실려면 나머지 키를 입력해주세요.)" << endl;
			num_try = 0;
			cin >> re;
			if (re == 1)
				return true;
			else
				cout << "\n숫자를 입력해주세요: " << endl;
			make_random();
		}
		return false;
	}
	void corret() {
		while (1) {
			cin >> num;
			for (int a = 0; a <= 2; a++) {
				num_cin[2 - a] = num % 10;
				num /= 10;
			}

			for (int a = 0; a <= 2; a++) {
				for (int b = 0; b <= 2; b++) {
					if (num_cin[a] == rand_cin[b])
					{
						if (a == b) {
							strike++;
							break;
						}
						else {
							ball++;
							break;
						}
					}
					else {
						if (b == 2)
							out++;
					}
				}
			}
			cout << "스트라이크:" << strike << ",볼:" << ball << ",아웃:" << out << endl;
			num_try += 1;
			if (re_start() == true) {
				break;
			}
			strike = 0; ball = 0; out = 0;
		}
	}
};
int main() {
	cout << "*************숫자 맞추기 게임*************";
	cout << "\n\n              [게임 규칙]                    " << endl;
	cout << "숫자와 자리가 모두 맞으면 스트라이크, 숫자만 맞으면 볼, 틀렸으면 아웃입니다." << endl;
	cout << "중복된 숫자는 사용할 수 없습니다." << endl;
	cout << "0부터 9까지의 숫자를 입력할 수 있습니다." << endl;
	cout << "\n3개의 숫자를 입력해주세요: " << endl;
	srand(time(NULL));
	baseball_game base;
	base.make_random();
	base.corret();
}