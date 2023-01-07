#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

int End();
float** float_array(size_t N, size_t M);
float** inizi2(int N, float** first, float** second, float** last, float** name);
void research(float** zh, float** first, float** second, float** last, float** name, int N, float sel);
void table(float** name, int N, float** first, float** second, float** last, int** zh);
float** charact(float** first, float** second, float** last, int sel, int sel2);
float** charactn(float** name, int sel);
float** ot(float** first, float** second, float** last, int N);
float** random(float** first, float** second, float** last, int N, float** name);
float** sort(float** first, float** second, float** last, float** names, int N, int** zh);
int** zhrebiy(int** zh, int N);
int** int_array(size_t N, size_t M);
void researchm(float** zh, float** first, float** second, float** last, float** name, int N);
int load(float** first, float** second, float** last, float** name, int N);
int save(float** first, float** second, float** last, float** name, int N, int** zh);
void research1(float** name, float** first, float** second, float** last, int N);
void research2(float** name, float** first, float** second, float** last, int N);

void main()
{
	setlocale(LC_ALL, "rus");
	
	int n, n1, selection, end = 1, selection1, selection2, selection3, selection4, selection5;
	
	
	float** nm = float_array(99, 20);
	float** h = float_array(99, 6);
	float** m = float_array(99, 6);
	float** s = float_array(99, 6);
	int* zh = int_array(99, 6);

	printf("Введите кол-во гонщиков: ");
	scanf_s("%d", &n);
	inizi2(n, h, m, s, nm);
	zhrebiy(zh, n);
	system("cls");
	while (1)
	{		
		printf("Программа результатов матчей.\n");
		printf("Функции:\n1) Показать таблицу.\n2) Изменить параметры гонщиков.\n3) Заполнить случайными числами.\n4) Очистить поля.\n5) Изменить кол-во гонщиков.\n");
		printf("6) Поиск.\n7) Сохранение файла.\n8) Загрузка файла.\n9) Выход.\n");
		printf("Введите функцию: ");
		scanf_s("%d", &selection);
		system("cls");
		switch (selection)
		{
		case 1:
		{
			table(nm, n, h, m, s, zh);
			end = End();
			
			break;
		}
		case 2:
		{
			printf("1) Изменить номер автомобиля.\n2) Изменить время заезда.\nВыберите функцию: ");
			scanf_s("%d", &selection5);
			system("cls");
			switch (selection5)
			{
			case 1:
			{
				printf("Введите место гонщика: ");
				scanf_s("%d", &selection1);
				system("cls");
				charactn(nm, (selection1-1));
				
				break;
			}
			case 2:
			{
				printf("Введите место гонщика: ");
				scanf_s("%d", &selection1);
				
				system("cls");
				printf("\nВведите номер заезда: ");
				scanf_s("%d", &selection2);
				system("cls");
				charact(h, m, s, (selection1-1), (selection2-1));
				
				system("cls");
				
				break;
			}
			}	
			break;
		}
		case 3:
		{
			printf("Заполнить случайными числами?\n1) Да.\n2) Нет.\nВведите функцию: ");
			scanf_s("%d", &selection3);
			system("cls");
			switch (selection3)
			{
			case 1:
			{
				random(h, m, s, n, nm);
				break;
			}
			case 2:
			{
				break;
			}
			break;
			}
			break;
		}
		case 4:
		{
			printf("Очистить поля?\n1) Да.\n2) Нет.\nВведите функцию: ");
			scanf_s("%d", &selection4);
			system("cls");
			switch (selection4)
			{
			case 1:
			{
				
				inizi2(n, h, m, s, nm);
				zhrebiy(zh, n);
				break;
			}
			case 2:
			{
				break;
			}
			break;
			}
			break;
		}
		case 5:
		{
			printf("Введите кол-во гонщиков: ");
			scanf_s("%d", &n);
			system("cls");
			
			inizi2(n, h, m, s, nm);
			zhrebiy(zh, n);
			break;
		}
		case 6:
		{
			int sel1;
			printf("1) Найти по месту.\n2) Найти по номеру автомобиля.\n3) Поиск наибольшего времени в заезде.\n4) Поиск наименьшего времени в заезде.\nВведите функцию: ");
			scanf_s("%d", &sel1);
			switch (sel1)
			{
			case 1:
			{
				printf("Введите место гонщика: ");
				scanf_s("%d", &selection1);
				research(zh, h, m, s, nm, n, selection1);
				end = End();
				break;
			}
			case 2:
			{
				researchm(zh, h, m, s, nm, n, sel1);
				end = End();
				break;
			}
			case 3:
			{
				research1(nm, h, m, s, n);
				end = End();
				break;
			}
			case 4:
				research2(nm, h, m, s, n);
				end = End();
				break;
			}
			break;
		}
		case 7:
		{
			printf("Сохранение файла.\n");
			save(h, m, s, nm, n, zh);
			end = End();
			break;
		}
		case 8:
		{
			printf("Загрузка файла.\n");
			load(h, m, s, nm, n);			
			printf("\nВведите кол-во гонщиков: ");
			scanf_s("%d", &n);
			printf("\n");
			zhrebiy(zh, n);			
			break;
		}
		case 9:
		{
			end = 2;
			return end;
			break;
		}

		}
		if (end == 2)
		{
			return end;
			break;
		}
	}
	
	return 0;
}
	
int** zhrebiy(int** zh, int N)
{
	for (int i = 0; i < N; i++)
	{
		zh[i][i] = i + 1;
	}
	return zh;
}




void table(float** name, int N, float** first, float** second, float** last,int** zh)
{	
	
	ot(first, second, last, N);
	sort(first, second, last, name, N, zh);
	printf("|%6s|%15s|%12s|%12s|%12s|%12s|%12s|%8s|\n", "Жребий", "Номер гонщика", "1-Заезд", "2-Заезд", "3-Заезд", "Кол-во очков", "Общее время", "Место");
	for (int i = 0; i < N; i++)
	{
		
		printf("%6d", zh[i][i]);
		printf("%16.0f", name[i][i]);
		for (int k = 0; k < 3; k++)
		{
			printf("%5.0f:%2.0f:%4.1f", first[i][k], second[i][k], last[i][k]);
		}
		printf("%10d", N - i);
		printf("%7.0f:%2.0f:%4.1f", first[i][3], second[i][3], last[i][3]);
		printf("%8d", i + 1);
		printf("\n");
		first[i][3] = 0;
		second[i][3] = 0;
		last[i][3] = 0;
	}
	
}



float** inizi2(int N, float** first, float** second, float** last, float** name)
{
	for (int k = 0; k < N; k++)
	{
		for (int l = 0; l < 4; l++)
		{
			first[k][l] = 0;
			second[k][l] = 0;
			last[k][l] = 0;
			name[k][k] = 0;
		}
	}
	return first, second, last, name;
}

float** float_array(size_t N, size_t M)
{
	float** A = (float**)malloc(N * sizeof(float*));
	for (int i = 0; i < N; i++) 
	{
		A[i] = (float*)malloc(M * sizeof(float));
	}
	return A;
}

int** int_array(size_t N, size_t M)
{
	int** A = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		A[i] = (int*)malloc(M * sizeof(int));
	}
	return A;
}



int End() 
{
	int N;
	printf("\n\n");
	printf("Продолжить программу?\n1) Да.\n2) Нет.\n");
	printf("Команда: ");
	scanf_s("%d", &N);
	printf("\n\n");
	system("cls");

	return N;
}

float** charact(float** first, float** second, float** last, int sel, int sel2)
{
	printf("Введите часы: ");
	scanf_s("%f", &first[sel][sel2]);
	printf("\n");
	printf("Введите минуты: ");
	scanf_s("%f", &second[sel][sel2]);
	printf("\n");
	printf("Введите секунды: ");
	scanf_s("%f", &last[sel][sel2]);
	printf("\n");

	return first, second, last;
}

float **charactn(float** name, int sel)
{	
	printf("Введите номер автомобиля гонщика: ");
	scanf_s("%f", &name[sel][sel]);
	system("cls");
	printf("\n");
	
	return name;
}

float** ot(float** first, float** second, float** last, int N)
{
	for (int k = 0; k < N; k++)
	{
		for (int l = 0; l < 3; l++)
		{
			first[k][3] += first[k][l];
			second[k][3] += second[k][l];
			last[k][3] += last[k][l];
		}
		while (last[k][3] >= 60)
		{
			second[k][3] += 1;
			last[k][3] -= 60;
		}
		while (second[k][3] >= 60)
		{
			first[k][3] += 1;
			second[k][3] -= 60;
		}
	}

	return first, second, last;
}

float** random(float** first, float** second, float** last, int N, float** name)
{
	for (int i = 0; i < N; i++)
	{
		name[i][i] = 100 + rand() % 899;
		for (int k = 0; k < 3; k++)
		{
			
			first[i][k] = 0 + rand() % 5;
			second[i][k] = 0 + rand() % 55;
			last[i][k] = 0 + rand() % 55;
		}
	}	
	return name, first, second, last;
}

float** sort(float** first, float** second, float** last, float** names, int N, int** zh)
{
	
	float name;
	float temp_h[6], temp_m[6], temp_s[6], temp_z, times1[99];

	for (int i = N - 1; i >= 0; i--)
	{
			
		for (int j = 0; j < i; j++)
		{
			times1[j] = first[j][3] * 3600 + second[j][3] * 60 + last[j][3];
			times1[j + 1] = first[j + 1][3] * 3600 + second[j + 1][3] * 60 + last[j + 1][3];
			if (times1[j] > times1[j + 1])
			{
				for (int k = 0; k < 4; k++)
				{
						temp_z = zh[j][j];
						temp_h[k] = first[j][k];
						temp_m[k] = second[j][k];
						temp_s[k] = last[j][k];					
						name = names[j][j];
				}
				for (int k = 0; k < 4; k++)
				{
					    zh[j][j] = zh[j + 1][j + 1];
						first[j][k] = first[j + 1][k];
						second[j][k] = second[j + 1][k];
						last[j][k] = last[j + 1][k];
						names[j][j] = names[j + 1][j + 1];
				}
				for (int k = 0; k < 4; k++)
				{
					    zh[j + 1][j + 1] = temp_z;
						first[j + 1][k] = temp_h[k];
						second[j + 1][k] = temp_m[k];
						last[j + 1][k] = temp_s[k];
						names[j + 1][j + 1] = name;
				}
			}				
		}
	} 
	return first, second, last, names, zh;
} 

void research(float** zh, float** first, float** second, float** last, float** name, int N, float sel)
{
	
	
	ot(first, second, last, N);
	sort(first, second, last, name, N, zh);
	
	for (int i = 0; i < N; i++)
	{
		if (sel - 1 == i)
		{
			printf("|%16s|%12s|%12s|%12s|%12s|%12s|%8s|\n", "Номер гонщика", "1-Заезд", "2-Заезд", "3-Заезд", "Кол-во очков", "Общее время", "Место");
			
			printf("%16.0f", name[i][i]);
			for (int k = 0; k < 3; k++)
			{
				printf("%5.0f:%2.0f:%4.1f", first[i][k], second[i][k], last[i][k]);
			}
			printf("%10d", N - i);
			printf("%7.0f:%2.0f:%4.1f", first[i][3], second[i][3], last[i][3]);
			printf("%8d", i + 1);
			printf("\n");
					
		}		
		first[i][3] = 0;
		second[i][3] = 0;
		last[i][3] = 0;
	}
}

void research1(float** name, float** first, float** second, float** last, int N)
{
	float nm;
	int sel2, i = 0;
	float time_int = 0, max_s = 0, max_m = 0, max_h = 0;
	printf("Введите номер заезда.\n");
	scanf_s("%d", &sel2);
	system("cls");
	for (; i < N; i++)
	{
		time_int = first[i][sel2 - 1] * 3600 + second[i][sel2 - 1] * 60 + last[i][sel2 - 1];
		if (time_int > max_s)
		{
			max_s = time_int;
			nm = name[i][i];
		}
	}
	while ( max_s >= 60)
	{
		max_s -= 60;
		max_m += 1;
	}
	while (max_m > 59)
	{
		max_m -= 60;
		max_h += 1;
	}
	printf("\n\tНаибольшее время заезда: %3.0f:%2.0f:%4.1f\t\tНомер гонщика: %10.0f", max_h, max_m, max_s, nm);
	printf("\n");
	
	
}

void research2(float** name, float** first, float** second, float** last, int N)
{
	float nm;
	int sel21;
	float time_int = 0, min_s = 150000, min_m = 0, min_h = 0;
	printf("Введите номер заезда.\n");
	scanf_s("%d", &sel21);
	system("cls");
	for (int i = 0; i < N; i++)
	{
		time_int = first[i][sel21 - 1] * 3600 + second[i][sel21 - 1] * 60 + last[i][sel21 - 1];
		if (time_int < min_s)
		{
			min_s = time_int;
			nm = name[i][i];
		}
	}
	while ( min_s >= 60)
	{
		min_s -= 60;
		min_m += 1;
	}
	while ( min_m > 59)
	{
		min_m -= 60;
		min_h += 1;
	}
	printf("\n\tНаименьшее время заезда: %3.0f:%2.0f:%4.1f\t\tНомер гонщика: %10.0f", min_h, min_m, min_s, nm);
	
}

void researchm(float** zh, float** first, float** second, float** last, float** name, int N)
{
	float sel;		
	ot(first, second, last, N);
	sort(first, second, last, name, N, zh);
	printf("Введите номер автомобиля гонщика, чтобы узнать о нем информацию: ");
	scanf_s("%f", &sel);
	system("cls");
	
	for (int i = 0; i < N; i++)
	{
		if (sel == name[i][i])
		{
			printf("\n|%15s|%12s|%12s|%12s|%12s|%12s|%8s|\n", "Номер гонщика", "1-Заезд", "2-Заезд", "3-Заезд", "Кол-во очков", "Общее время", "Место");			
			printf("%16.0f", name[i][i]);
			for (int k = 0; k < 3; k++)
			{
				printf("%5.0f:%2.0f:%4.1f", first[i][k], second[i][k], last[i][k]);
			}
			printf("%10d", N - i);
			printf("%7.0f:%2.0f:%4.1f", first[i][3], second[i][3], last[i][3]);
			printf("%8d", i+1);
			printf("\n");
			
		}
		first[i][3] = 0;
		second[i][3] = 0;
		last[i][3] = 0;
	}
			
		
}

int load(float** first, float** second, float** last,  float** name, int N) 
{
	FILE* file;
	char* fname[20];
	char reading[20], txt[5] = ".txt";
	int count = 0;
	

	printf("Введите название файла: ");
	scanf("%s", fname);
	strcat(fname, txt);
	file = fopen(fname, "r");
	printf("\n\n");

	while (fscanf(file, "%f %f %f %f %f %f %f %f %f %f %f %f %f",  &(name[count][count]), &(first[count][0]), &(second[count][0]), &(last[count][0]), &(first[count][1]), &(second[count][1]), &(last[count][1]), &(first[count][2]), &(second[count][2]), &(last[count][2]), &(first[count][3]), &(second[count][3]),&(last[count][3])) != EOF)
	{
		printf("%3.0f %3.0f %3.0f %3.2f %3.0f %3.0f %3.2f %3.0f %3.0f %3.2f %3.0f %3.0f %3.2f\n", name[count][count], first[count][0], second[count][0], last[count][0], first[count][1], second[count][1], last[count][1], first[count][2], second[count][2], last[count][2], first[count][3], second[count][3], last[count][3]);
		count++;		
	}

	printf("\n\n%d - Кол-во гонщиков.", count);

	printf("\n\n");
	N = count;
	fclose(file);
	return N, first, second, last, name;
}

int save(float** first, float** second, float** last, float** name, int N, int** zh) 
{
	ot(first, second, last, N);
	sort(first, second, last, name, N, zh);
	FILE* file;
	char* fname[20];
	char reading[20], txt[5] = ".txt";

	printf("Введите название файла: ");
	scanf("%s", fname);
	strcat(fname, txt);
	file = fopen(fname, "w");

	for (int i = 0; i < N; i++) 
	{
		
		fprintf(file, "%.0f\t ", name[i][i]);
		for (int k = 0; k < 4; k++)
		{
			fprintf(file, "%.0f %.0f %.1f\t ", first[i][k], second[i][k], last[i][k]);
		}
		fprintf(file, "\n");
	}

	fclose(file);
	return N;
}