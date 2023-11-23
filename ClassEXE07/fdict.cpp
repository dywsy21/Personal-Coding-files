#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>

#define WORD_SIZE 50
#define COMMENT_SIZE 100

void dict_file(int &word_num, char (*&word)[WORD_SIZE], char (*&comment)[COMMENT_SIZE])
{
    std::ifstream inf("words.txt");
    std::istringstream iss;
    std::string word_t;
    std::string temp, comment_t;
    if(!inf)
    {
        std::cout << "Cannot found the wordlist file" << std::endl;
        return;
    }
    
    std::string line;
    
    getline(inf, line);
    iss.str(line);
    iss >> word_num;

    word = (char (*)[WORD_SIZE])malloc(sizeof(char) * WORD_SIZE * word_num);
    comment = (char (*)[COMMENT_SIZE])malloc(sizeof(char) * COMMENT_SIZE * word_num);
    memset(word, 0, sizeof(char) * WORD_SIZE * word_num);
    memset(comment, 0, sizeof(char) * COMMENT_SIZE * word_num);
    
    int i = 0;
    
    while(getline(inf, line))
    {
        iss.clear();
        iss.str(line);
        iss >> word_t;
        comment_t = "";
        while(iss >> temp)
        {
            comment_t += temp;
        }
        
        strcpy(word[i], word_t.c_str());
        strcpy(comment[i], comment_t.c_str());
        
        i++;
    }

    inf.close();

}

// ��ȷ���0
// ���ڷ���1�����ڱ�ʾstr1����ĸ������str2����
// С�ڷ���-1 С�ڱ�ʾstr1����ĸ������str2ǰ��
int strtcmp(char str1[], char str2[])
{
	char t1, t2;
	char diff = 'a' - 'A';
	int i = 0;

	while(str1[i] && str2[i])
	{
		t1 = str1[i]; t2 = str2[i];
		if(str1[i] > 'A' && str1[i] < 'Z')
			t1 += diff;

		if(str2[i] > 'A' && str2[i] < 'Z')
			t2 += diff;

		if(t1 > t2) return 1;
		if(t1 < t2) return -1;

		++i;
	}

	if(str1[i] == str2[i]) return 0;
	else if(str1[i] == 0) return -1;
	else if(str2[i] == 0) return 1;
}


// key��ʾ�����ѯ�ĵ���
// words[i]��ʾ���ʿ���ĵ�i������
// size��ʾ���ʿⵥ�ʴ�С
// �Ƚϵ��ʵķ���:
//     strtcmp(key, words[i])
// ���key �� words[j]��ͬ��search�������ص������j
// ���������ٸ��ݸ���������Ӧ�ĵ�����˼
// �Ҳ�������key����-1

// ����������ʾ�����ö��ֲ������search����

int search(char key[], char words[][WORD_SIZE], int size)
{
	int lo=1,hi=size,mid=(lo+hi)/2;
	while(lo!=hi)
	{
		int cmp=strtcmp(key,words[mid]);
		if(cmp==0) return mid;
		if(cmp==1) lo=mid+1;
		if(cmp==-1) hi=mid-1;
		mid=(lo+hi)/2;
	}
	return -1;
}



void help()
{
	printf("A Mini Dictionary.\nCopyright (c) 2022. All Rights Reserved.\n");
	printf("Type exit to exit.\n");
}

// ����ʱ����words.txt���ں����е�fdict.exeͬһ��Ŀ¼��
int main()
{	
	int size=24678;	
	char (*words)[WORD_SIZE];	
	char (*comments)[COMMENT_SIZE];	
	dict_file(size, words, comments);

	char key[WORD_SIZE];
	int i;

	help();

	while(1)
	{
        scanf("%s", key);
		if(strtcmp(key, "exit") == 0)
			break;

		i = search(key, words, size);

		if(i != -1)
		{
			printf("%s\n", comments[i]);
		}
		else
		{
			printf("No such word\n");
		}
	}

	free(words);	
	free(comments);
	
	return 0;
}
