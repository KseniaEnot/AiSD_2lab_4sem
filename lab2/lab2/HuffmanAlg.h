#pragma once
#include "PriorityQueue.h"
#include "RedBlackTree.h"
#include "Stack.h"
class HuffmanAlg
{
private: //K- вес дерева (кол-во повторений символов),V - дерево
	class Node
	{
	public:
		Node(int f = 0, Node* lC = nullptr, Node* rC = nullptr, char l = '\n') {
			frequence = f;
			letter = l;
			left = lC;
			right = rC;
			parent = nullptr;
		};
		~Node() {};
		int frequence;
		char letter;
		Node* left;
		Node* right;
		Node* parent;
	};
	void copyBoolArray(bool* copy, bool* str, int size) {
		for (size_t i = 0; i < size; i++)
			copy[i] = str[i];
	};
	Node* root;
	char* str;
	size_t sizeStr;
	bool* readyCode;
	size_t sizeReadyCode;
	struct strArr
	{
		bool* str = NULL;
		int size = 0;
	};
	RedBlackTree<char, strArr*> codeLetter;
public:
	HuffmanAlg(char* _str){
		codeLetter = RedBlackTree<char, strArr*>();
		str = _str;
		sizeStr = 0;
		for (size_t i = 0; str[i]!='\n'; i++)
			sizeStr++;
		PriorityQueue<Node*> PQ;
		Node* bufNode_1;
		Node* bufNode_2;
		int chars[256] = { 0 };
		for (int i = 0; str[i] != '\n'; i++)
			chars[str[i]+128]++;
		int countLetter = 0;
		for (int i = 0; i < 256; i++)
			if (chars[i] != 0) {
				countLetter++;
				bufNode_1 = new Node(chars[i], nullptr, nullptr, (i-128));
				PQ.push(bufNode_1, chars[i]);
			}
		int bufInt;
		bufInt = PQ.head_priority();
		bufNode_1 = PQ.pop();
		for (size_t i = 0; (i < countLetter) && (!PQ.isEmpty()); i++)
		{
			bufInt += PQ.head_priority();
			bufNode_2 = PQ.pop();
			root = new Node(bufInt, bufNode_1, bufNode_2);
			bufNode_1->parent = root;
			bufNode_2->parent = root;
			PQ.push(root, root->frequence);
			if (!PQ.isEmpty())
			{
				bufInt = PQ.head_priority();
				bufNode_1 = PQ.pop();
			}
		}
		bool* bufStr = new bool[countLetter / 2 + 1]; //максимальная высота дерева
		memset(bufStr, NULL, countLetter / 2 + 1);
		bool* copyStr = NULL;
		size_t indexStr = 0;
		unsigned int bufCodeLetter = 0;
		Stack<Node*> dft;
		if (root->right != nullptr)
		{
			dft.push(root->right);
		}
		bufNode_1 = root;
		strArr* bufStrArr = new strArr;
		while (!dft.isEmpty())
		{
			while (bufNode_1->left != nullptr)
			{
				bufStr[indexStr] = 0;
				indexStr++;
				bufNode_1 = bufNode_1->left;
				if (bufNode_1->right != nullptr)
				{
					dft.push(bufNode_1->right);
				}
			}
			copyStr = new bool[indexStr];
			copyBoolArray(copyStr, bufStr, indexStr);
			bufStrArr = new strArr;
			bufStrArr->size = indexStr;
			bufStrArr->str = copyStr;
			codeLetter.insert(bufNode_1->letter, bufStrArr);//проверяем верхушку стека и родителя того где находимся
			indexStr--;
			while ((bufNode_1->parent != nullptr) && (bufNode_1->parent->right != dft.get_last()))
			{
				bufNode_1 = bufNode_1->parent;
				indexStr--;
			}
			bufNode_1 = dft.pop();
			if (bufNode_1->right != nullptr)
			{
				dft.push(bufNode_1->right);
			}
			bufStr[indexStr] = 1;
			indexStr++;
		}
		copyStr = new bool[indexStr];
		copyBoolArray(copyStr, bufStr, indexStr);
		bufStrArr = new strArr;
		bufStrArr->size = indexStr;
		bufStrArr->str = copyStr;
		codeLetter.insert(bufNode_1->letter, bufStrArr);
		readyCode = NULL;
	}
	bool* Code(int& codeSize) {
		bool* copyStr;
		codeSize = 0;
		for (int i = 0; str[i] != '\n'; i++) {
			codeSize += codeLetter.find(str[i])->size;
		}
		sizeReadyCode = codeSize;
		readyCode = new bool[codeSize];
		size_t indexStr=0;
		for (int i = 0; str[i] != '\n'; i++) {
			copyStr = codeLetter.find(str[i])->str;
			for (size_t j = 0; j< codeLetter.find(str[i])->size; j++) {
				readyCode[indexStr] = copyStr[j];
				indexStr++;
			}
		}
		return readyCode;
	}
	char* Decode(int& sizeStrDecode) {
		char* decodeStr = new char[sizeStr];
		sizeStrDecode = sizeStr;
		if (readyCode != NULL) //ПРВЕРКА ЕСЛИ 1 СИМВОЛ
		{
			size_t indexCode=0;
			Node* curNode = root;
			size_t indexDecode = 0;
			while (indexCode< sizeReadyCode)
			{
				if ((readyCode[indexCode]==0)&&(curNode->left!=nullptr))
				{
					curNode = curNode->left;
					indexCode++;
				}
				else if ((readyCode[indexCode] == 1) && (curNode->right != nullptr)) {
					curNode = curNode->right;
					indexCode++;
				}
				else {
					decodeStr[indexDecode] = curNode->letter;
					indexDecode++;
					curNode = root;
				}
			}
			decodeStr[indexDecode] = curNode->letter;
		}
		else {
			throw "EXDOMINARTE!";
		}
		return decodeStr;
	}	
};

#include "PriorityQueue.cpp"
