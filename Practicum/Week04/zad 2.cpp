#include <iostream>
#include <fstream>

constexpr size_t MAX_TASK_SIZE = 1000;
constexpr size_t NUM_OF_PROBLEMS_ON_EXAM = 3;
class Problem {
	char taskText[MAX_TASK_SIZE] = "";
	char* task = &taskText[0];
	char answer;
	size_t points;
	char password[MAX_TASK_SIZE] = "Default";
public:
	Problem() { };

	Problem(const char task[],const char answer,const size_t points,const char password[]) {
		int iter = 0;
		this->answer = answer;
		this->points = points;

		while (task[iter]) {
			this->task[iter] = task[iter];
			iter++;
		}
		this->task[iter] = task[iter];

		iter = 0;

		while (password[iter]) {
			this->password[iter] = password[iter];
			iter++;
		}
		this->password[iter] = password[iter];

	}

	bool checkPassword(const char password[]) {
		int iter = 0;
		if (strlen(this->password) != strlen(password)) {
			std::cout << "Wrong Password" << std::endl;
			return false;
		}

		while (this->password[iter]) {
			if (password[iter] != this->password[iter]) {
				std::cout << "Wrong Password" << std::endl;
				return false;
			}
			iter++;
		}
		return true;
	}

	void changeTask(const char task[],const char password[]) {

		if (!checkPassword(password)) {
			return;
		}
		int iter = 0;

		while (task[iter]) {
			this->task[iter] = task[iter];
			iter++;
		}
		this->task[iter] = '\0';
	}

	void changePoints(const size_t points,const char password[]) {

		if (!checkPassword(password)) {
			return;
		}

		this->points = points;
	}

	void changeAnswer(const char answer,const char password[]) {

		if (!checkPassword(password)) {
			return;
		}

		this->answer = answer;
	}

	void changePassword(const char oldPassword[],const char newPassword[]) {

		if (!checkPassword(oldPassword)) {
			return;
		}

		int iter = 0;
		while (newPassword[iter]) {
			this->password[iter] = newPassword[iter];
			iter++;
		}
		this->password[iter] = '\0';
	}

	char* getTask() const {
		return task;
	}

	char getAnswer() const {
		return answer;
	}

	size_t getPoints() const {
		return points;
	}
};

class Exam {

	Problem problemArr[NUM_OF_PROBLEMS_ON_EXAM];
	
public:
	void modifyProblemTask(const char* task, const char* password, const size_t numOfProblem) {
		problemArr[numOfProblem - 1].changeTask(task, password);
	}

	void modifyProblemAnswer(const char answer, const char* password, const size_t numOfProblem) {
		problemArr[numOfProblem-1].changeAnswer(answer, password);
	}

	void modifyProblemPoints(const size_t points, const char* password, const size_t numOfProblem) {
		problemArr[numOfProblem - 1].changePoints(points, password);
	}
	
	void changeProblemPassword(const char* oldPassword, const char* newPassword,const size_t numOfProblem) {
		problemArr[numOfProblem-1].changePassword(oldPassword, newPassword);
	}

	size_t calculateMaxPoints() {
		size_t sum = 0;
		for (int i = 0; i < NUM_OF_PROBLEMS_ON_EXAM; i++) {
			sum = sum + problemArr[i].getPoints();
		}
		return sum;
	}
};

void writeExamToFile(Exam* exam) {

	std::ofstream ofs("Exam.dat", std::ios::binary);

	if (!ofs.is_open()) {
		std::cout << "Error";
		return;
	}

	ofs.write((const char*)exam, sizeof(Exam));
	ofs.close();

}

void readExamFromFile(Exam* exam) {

	std::ifstream ifs("Exam.dat", std::ios::binary);

	if (!ifs.is_open()) {
		std::cout << "Error";
		return;
	}

	ifs.read((char*)exam, sizeof(Exam));
	ifs.close();

}
int main() {
	
}
