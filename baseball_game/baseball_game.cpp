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
			cout << "\n*************�¸��ϼ̽��ϴ�!!*************\n" << endl;
			cout << "" << num_try << "�� ���� ���߼̽��ϴ�!" << endl;
			cout << "�����ϽǷ��� 1�� �����ּ���!(�ٽ��ϽǷ��� ������ Ű�� �Է����ּ���.)" << endl;
			num_try = 0;
			cin >> re;
			if (re == 1)
				return true;
			else
				cout << "\n���ڸ� �Է����ּ���: " << endl;
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
			cout << "��Ʈ����ũ:" << strike << ",��:" << ball << ",�ƿ�:" << out << endl;
			num_try += 1;
			if (re_start() == true) {
				break;
			}
			strike = 0; ball = 0; out = 0;
		}
	}
};
int main() {
	cout << "*************���� ���߱� ����*************";
	cout << "\n\n              [���� ��Ģ]                    " << endl;
	cout << "���ڿ� �ڸ��� ��� ������ ��Ʈ����ũ, ���ڸ� ������ ��, Ʋ������ �ƿ��Դϴ�." << endl;
	cout << "�ߺ��� ���ڴ� ����� �� �����ϴ�." << endl;
	cout << "0���� 9������ ���ڸ� �Է��� �� �ֽ��ϴ�." << endl;
	cout << "\n3���� ���ڸ� �Է����ּ���: " << endl;
	srand(time(NULL));
	baseball_game base;
	base.make_random();
	base.corret();
}