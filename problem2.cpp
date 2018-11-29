#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<fstream>
#include<sstream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//addList = new ListNode(0);
		int carry = 0;
		//addList -> val = 0;
		//addList -> next = NULL;
		ListNode* addList = NULL;
		ListNode* p = NULL;
		int addval;

		while ((l1 != NULL) && (l2 != NULL)) {
			addval = addNode(l1->val, l2->val, carry);
			if (addList == NULL) {
				addList = new ListNode(addval);
				p = addList;
			}
			else {
				insert(p, addval);
			}
			l1 = l1->next;
			l2 = l2->next;
		}

		if (carry == 0) {
			if (l1 != NULL) {
				while (l1 != NULL) {
					insert(p, l1->val);
					l1 = l1->next;
				}
			}
			if (l2 != NULL) {
				while (l2 != NULL) {
					insert(p, l2->val);
					l2 = l2->next;
				}
			}
		}
		else {//carry==1
			if (l1 != NULL) {
				while (l1 != NULL) {
					addval = addNode(l1->val, 0, carry);
					insert(p, addval);
					l1 = l1->next;
				}
			}
			if (l2 != NULL) {				
				while (l2 != NULL) {
					addval = addNode(0, l2->val, carry);
					insert(p, addval);
					l2 = l2->next;
				}
			}
			if (carry == 1) {
				insert(p, 1);
			}
		}


		return addList;
	}
private:
	int addNode(int nodeval1, int nodeval2, int &carry) {
		int addval;
		addval = nodeval1 + nodeval2 + carry;
		if (addval >= 10) {
			addval = addval - 10;
			carry = 1;
		}
		else
			carry = 0;

		return addval;
	}

	void insert(ListNode* &p, int i) {
		ListNode* node = new ListNode(i);
		node->next = p->next;
		p->next = node;
		p = p->next;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* l1 = stringToListNode(line);
		getline(cin, line);
		ListNode* l2 = stringToListNode(line);

		ListNode* ret = Solution().addTwoNumbers(l1, l2);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}