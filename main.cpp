#include "km3.h"


using namespace std;

char digits[] = "0123456789ABCDEF"; // hex

const uint8_t*


as_bytes(const void* data)
{
	return reinterpret_cast<const uint8_t*>(data);
}
char nibble_to_hex(uint8_t i)
{
	return digits[i & 0xf];
}

void print_in_hex(uint8_t byte)
{
	cout<<nibble_to_hex(byte>>4)<<nibble_to_hex(byte & 0xf);
}

void print_in_hex(const void* data, size_t size)
{
	const uint8_t *bytes=as_bytes(data);

	for (size_t i = 0; i<size; i++)
    {
		print_in_hex(bytes[i]);
		if((i + 1)%16==0)
        {
			cout<<'\n';
		}
		else
        {
			cout<<' ';
		}
	}
}

char bit_digit(uint8_t byte, uint8_t bit)
{
	if (byte &(0x1 << bit))
    {
		return '1';
	}
	return '0';
}

void print_in_binary(uint8_t byte)
{
	for (int bit = 7; bit>=0; bit--)
    {
		cout<<bit_digit(byte, bit);
	}
}

void print_in_binary(const void* data, size_t size)
{
	const uint8_t *bytes = as_bytes(data);

	for (size_t i = 0; i < size; i++)
    {
		print_in_binary(bytes[i]);

		if((i + 1)%4==0)
        {
			cout<<'\n';
		}
		else {
			cout<<' ';
		}
	}
}

void f_tolower(char *s)
{
	for (; *s; s++)
	*s = tolower(*s);
}

void get_string(char *s,size_t n)
{
	fgets(s, n, stdin);
	if (s[strlen(s) - 1] == '\n')
    {
        s[strlen(s) - 1] = '\0';
    }
}

int bitwise_operators()
{


        uint16_t a,b,result=0;
        char operat[8];
        int truth=0;


        cout<<"Enter the expression:";

        cin>>a>>operat>>b;

        if(operat[0]=='&')
        {
            result=a&b;
            truth=1;
        }
        else if(operat[0]=='|')
        {
            result=a|b;
            truth=2;
        }
        else if(operat[0]=='^')
        {
            result=a^b;
            truth=3;
        }
        else
        {
            cout<<"Unknown operation\n";
        }

        if (truth==1)
        {
            print_in_hex(&a, sizeof(uint16_t));
            cout<<" & ";
            print_in_hex(&b, sizeof(uint16_t));
            cout<<" = ";
            print_in_hex(&result, sizeof(uint16_t));
            cout<<"\n";
            print_in_binary(&a, sizeof(uint16_t));
            cout<<" &\n";
            print_in_binary(&b, sizeof(uint16_t));
            cout<<" =\n";
            print_in_binary(&result, sizeof(uint16_t));
            cout<<"\n";
        }
        if (truth==2)
        {
            print_in_hex(&a, sizeof(uint16_t));
            cout<<" | ";
            print_in_hex(&b, sizeof(uint16_t));
            cout<<" = ";
            print_in_hex(&result, sizeof(uint16_t));
            cout<<"\n";
            print_in_binary(&a, sizeof(uint16_t));
            cout<<" |\n";
            print_in_binary(&b, sizeof(uint16_t));
            cout<<" =\n";
            print_in_binary(&result, sizeof(uint16_t));
            cout<<"\n";
        }
        if (truth==3)
        {
            print_in_hex(&a, sizeof(uint16_t));
            cout<<" ^ ";
            print_in_hex(&b, sizeof(uint16_t));
            cout<<" = ";
            print_in_hex(&result, sizeof(uint16_t));
            cout<<"\n";
            print_in_binary(&a, sizeof(uint16_t));
            cout<<" ^\n";
            print_in_binary(&b, sizeof(uint16_t));
            cout<<" =\n";
            print_in_binary(&result, sizeof(uint16_t));
            cout<<"\n";
        }

	system("pause");
	return bitwise_operators();

}

struct Student
{
	char name[17];
	uint16_t god_postuplen;
	float sredn_ball;
	uint16_t pol : 1;
	uint16_t finish_kurs;
	Student *starosta;
};

int memory()
{
    SetConsoleCP(1251); //Ввод,
    SetConsoleOutputCP(1251); //Вывод кириллицы в консоли Windows.

	Student mass[3];
	uint16_t sex;
	for (int i=0;i<3;i++)//Цикл заполнения массива описывающий двух студентов одной группы и их старосту.
    {
		if(i!=0)
		{
		    cout<<"Студент"<<i<<":\n";

            mass[i].starosta = &mass[0];
        }
		else
		{
            mass[i].starosta = NULL;

            cout<<"Староста:\n";
        }

        cout<<"Имя: ";
        cin>>mass[i].name;
        cout<<"Год поступления:";
        cin>>mass[i].god_postuplen;
		cout<<"Средний балл: ";
		cin>>mass[i].sredn_ball;
		cout<<"Пол (0-1):";
		cin>>sex;
		mass[i].pol = sex;
		cout<<"Количество пройденных курсов:";
		cin>>mass[i].finish_kurs;
	}

	cout<<"Адрес массива:"<<(void*)mass<<"\n"; //адрес массива.
	cout<<"Размер массива:"<<sizeof(mass)<<"\n";//размер массива

	for(int i=0;i<3;i++)
    {
		cout << "Адрес элемента:"<< i <<":"<<(void*)&mass[i]<<"\n";//Цикл вывода адреса массива.
		cout << "Размер элемента:" <<i<<":"<<sizeof(Student)<<"\n";//Цикл размера трёх элементов массива
	}

	//Вывод для всех полей, кроме пола, одного из элементов массива.

	{
	    int i;

        cout<<"Введите номер студента для вывода всех его полей(1-2)\n";
        cin>>i;
        cout<<"Студент №"<<i;
        cout<<"\nИмя: адрес = "<<(void*)&mass[i].name<<" Смещение = "<<offsetof(Student, name)<<" Размер = "<<sizeof(mass[i].name)<<"\nШестнадцатеричное представление:\n";

        print_in_hex(&mass[i].name, sizeof(mass[i].name));

        cout<<"\nДвоичное представление:\n";

        print_in_binary(&mass[i].name, sizeof(mass[i].name));

        cout<<"\n\nГод поступления: адрес = "<<(void*)&mass[i].god_postuplen<<" Смещение = "<<offsetof(Student, god_postuplen)<<" Размер = "<<sizeof(mass[i].god_postuplen)<<"\nШестнадцатеричное представление:\n";

        print_in_hex(&mass[i].god_postuplen, sizeof(mass[i].god_postuplen));

        cout<<"\nДвоичное представление:\n";

        print_in_binary(&mass[i].god_postuplen, sizeof(mass[i].god_postuplen));

        cout<<"\n\nСредний балл: адрес = "<<(void*)&mass[i].sredn_ball<<" Смещение = "<<offsetof(Student, sredn_ball)<<" Размер = "<<sizeof(mass[i].sredn_ball)<<"\nШестнадцатеричное представление:\n";

        print_in_hex(&mass[i].sredn_ball, sizeof(mass[i].sredn_ball));

        cout<<"\nДвоичное представление:\n";

        print_in_binary(&mass[i].sredn_ball, sizeof(mass[i].sredn_ball));

        cout<<"\n\nКоличество пройденных курсов: адрес = "<<(void*)&mass[i].finish_kurs<<"Смещение = "<<offsetof(Student, finish_kurs)<<"Размер = "<<sizeof(mass[i].finish_kurs)<<"\nШестнадцатеричное представление:\n";

        print_in_hex(&mass[i].finish_kurs, sizeof(mass[i].finish_kurs));

        cout<<"\nДвоичное представление:\n";

        print_in_binary(&mass[i].finish_kurs,sizeof(mass[i].finish_kurs));

        cout<<"\n\nСтароста: адрес = "<<(void*)&mass[i].starosta<<"Смещение = "<<offsetof(Student, starosta)<<" Размер = "<<sizeof(mass[i].starosta)<<"\nШестнадцатеричное представление:\n";

        print_in_hex(&mass[i].starosta, sizeof(mass[i].starosta));

        cout<<"\nДвоичное представление:\n";

        print_in_binary(&mass[i].starosta, sizeof(mass[i].starosta));
    }

	//Вывод всех элементов массива.

	cout << "\nПолный массив:\n";

	print_in_hex(mass, sizeof(mass));

	cout << "\nДвоичное представление:\n";

	print_in_binary(mass, sizeof(mass));

	system("pause");
	return memory();
}



    using namespace std;
    const size_t MAX_SIZE = 256;
    const char not_allowed[] = "*\"<>?|";
    const char separators[] = " \r\n,.!?:;()-";

bool correct(char *Name)
{
	char mas[8];
	for (int i = 0; Name[i]; i++)
    {
		if(strchr(not_allowed, Name[i]) != 0)
        {
            return false;
        }
	}
	char *colon = strchr(Name, ':');
	if (colon != NULL) {
		if (colon - Name != 2)
			return false;
		if (colon[1] != '\\')
			return false;
		if (strrchr(Name, ':') != colon)
			return false;
	}
	char *fName = strrchr(Name, '\\');
	fName = fName ? fName++ : Name;
	char *ttext = strchr(fName, '.');
	if (ttext == NULL)
		strcat(Name, ".txt");
	else {
		strcpy_s(mas, ttext);
		f_tolower(mas);
		if (strcmp(mas, ".txt"))
			return false;
		}
	return true;
}

int strings()
{
    SetConsoleCP(1251); //Ввод,
    SetConsoleOutputCP(1251); //Вывод кириллицы в консоли Windows.

	char filename[MAX_SIZE];
	char str[MAX_SIZE];

	cout<<"input file:";
	get_string(filename, MAX_SIZE);

	if(correct(filename) == false)
    {
		cout<<"wrong name\n";
		return -1;
	}

	FILE *fin=fopen(filename,"r");

	if(fin == NULL)
	{
		cout<<"can't open file\n";
		return -1;
	}

	fseek(fin, 0, SEEK_END);
	size_t length = ftell(fin);

	fseek(fin, 0, SEEK_SET);
	char *text = new char[length + 1];

	memset(text, 0, length + 1);
	fread(text, 1, length, fin);

	cout<<"input line:";

	get_string(str, MAX_SIZE);

	const char *start = text;
	size_t count = 0;
	while (true)
    {
		const size_t separator_count = strspn(start, separators);
		start += separator_count;
		if(start[0] == '\0')
		{
			break;
		}

		const size_t word_length = strcspn(start, separators);

		if(word_length == strlen(str) && strncmp(str, start,word_length) == 0)
        {
			count++;
			cout.write(start, word_length);
			cout<<'\n';
		}

		start += word_length;
	}
	cout<<"result: "<<count<<"\n";

	fclose(fin);
	delete[] text;

    system("pause");
	return strings();
}


int main()
{
    int program;

    int sign_of_entry = 1;

    cout<<"1) Calculator for bitwise operations;"<<endl;
    cout<<"2) Representation and placement of data in memory"<<endl;
    cout<<"3) Working with strings"<<endl;

    cin>>program;

    switch(program)
    {
        case 1:
            cout<<"Calculator for bitwise operations"<<endl;

            if(sign_of_entry == 1)
            {
                cout<<"a"<<" "<<"&"<<" "<<"b"<<endl;
                cout<<"a"<<" "<<"|"<<" "<<"b"<<endl;
                cout<<"a"<<" "<<"^"<<" "<<"b"<<endl;

                sign_of_entry = 0;
            }

            bitwise_operators();
        break;
        case 2:
            cout<<"Representation and placement of data in memory"<<endl;
            memory();
        break;
        case 3:
            cout<<"Working with strings"<<endl;
            strings();
        break;
    }
}
