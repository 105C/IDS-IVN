#include "IDS.h"
void IDS_Entropy(int w, double averageEntropy, double k, double var_sqrt) {
	vector<string> messageWinodw;
	unordered_map<string, int> hash;
	string line;
	fstream read;
	fstream write;
	read.open("E:\\�������\\����\\��Ϣ��\\���ݼ�\\Fuzzy_attack_dataset.txt", ios::in);
	if (!read) {
		cout << "�޷����ļ�" << endl;
		return;
	}
	write.open("E:\\�������\\����\\��Ϣ��\\�Ա�ʵ��\\Fuzzy_attack_IDS_result.txt", ios::app);
	write << "k = " << k << endl;
	cout << "���ڼ�����Ϣ��..." << endl;
	int index = 0;
	while (getline(read, line)) {
		double entropy = 0.0;
		messageWinodw.push_back(line);
		if (messageWinodw.size() == w) {
			++index;
			for (int i = 0; i < messageWinodw.size(); ++i) {
				string tmp = messageWinodw[i].substr(40, 4);
				++hash[tmp];
			}
			for (unordered_map<string, int>::iterator it = hash.begin(); it != hash.end(); ++it) {
				double p = (double)it->second / w;
				entropy += (-(p * (log(p) / log(2))));
			}
			if (entropy < averageEntropy - k * var_sqrt || entropy > averageEntropy + k * var_sqrt) {
				write << index << " " << entropy << " " << "abnormal!" << endl;
			}
			messageWinodw.clear();
			hash.clear();
		}
	}
	read.close();
	write.close();
	cout << "�������..." << endl;
	return;
}

void Count_ID() {
	unordered_map<string, int> hash;
	string line;
	fstream read;
	fstream write;
	read.open("C:\\Users\\91221\\Desktop\\DoS_attack_dataset_oil.txt", ios::in);
	if (!read) {
		cout << "�޷����ļ�" << endl;
		return;
	}
	write.open("C:\\Users\\91221\\Desktop\\DoS_attack_dataset_oil_ID_count.txt", ios::app);
	cout << "��ʼͳ�Ƹ���ID������" << endl;
	int index = 0;
	while (getline(read, line)) {
			string tmp = line.substr(40, 4);
			++hash[tmp];
	}
	for (auto it = hash.begin(); it != hash.end(); ++it) {
		write << it->first << " " << it->second << endl;
	}
	read.close();
	write.close();
	cout << "�������..." << endl;
	return;
}