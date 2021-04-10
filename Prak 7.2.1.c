#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef char itemType;
typedef struct {
	itemType data[MAX];
	int front;
	int rear;
	int count;
} queue;

void initialisasi(queue *q);
int kosong(queue *q);
int penuh(queue *q);
void enqueue(itemType x, queue *q);
itemType dequeue(queue *q);

void tambah(queue *q);
void ambil(queue *q);
void minMax(queue *q);
void cari(queue *q);
void tampil(queue *q);

itemType cekCari(itemType z, queue *q);

void menu(queue *q);
int pilihan;

int main(){
	queue q;
	initialisasi(&q);
	
	do
		menu(&q);
	while(pilihan != 6);
}

void menu(queue *q){
	printf("========================\n");
	printf(" Menu Queue\n");
	printf("========================\n");
	printf("1. Tambah Data\n");
	printf("2. Hapus Data\n");
	printf("3. Tampilkan Data Min & Max\n");
	printf("4. Cari Data\n");
	printf("5. Cetak Isi Queue\n");
	printf("6. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihan);
	fflush(stdin);
	
	if(q->count == 0 && pilihan >= 2 && pilihan <= 3)
		printf("Data masih kosong gan :)\n");
	else {
		switch(pilihan){
			case 1:
				tambah(q);
				break;
			case 2:
				ambil(q);
				break;
			case 3:
				minMax(q);
				break;
			case 4:
				cari(q);
				break;
			case 5:
				tampil(q);
				break;
		}
	}
	
}

void initialisasi(queue *q){
	q->front = 0;
	q->rear = 0;
	q->count = 0;
}

void tambah(queue *q){
	itemType x;
	
	printf("%-25s", "Masukkan data"); printf(": ");
	scanf("%c", &x);
	fflush(stdin);
	
	enqueue(x, q);
}

void ambil(queue *q){
	printf("%c \n", dequeue(q));
}

int penuh(queue *q){
	return(q->count == MAX);
}

int kosong(queue *q){
	return(q->count == 0);
}

void enqueue(itemType x, queue *q){
	if(penuh(q))
		printf("Kondisi Penuh Gan :)\n");
	else {
		q->data[q->rear] = x;
		q->rear = (q->rear + 1) % MAX;
		(q->count)++;
	}
}

itemType dequeue(queue *q){
	itemType x;
	
	if(kosong(q))
		printf("Data kosong gan :)\n");
	else {
		x = q->data[q->front];
		q->front = (q->front + 1) % MAX;
		(q->count)--;
		return(x);
	}
}

void tampil(queue *q){
	int i, j, y;
	itemType x;
	
	j = q->front;
	y = q->count;
	
	for(i=0; i<MAX; i++){
		if(y == 0)
			break;
		else {
			x = q->data[j];
			j = (j + 1) % MAX;
			y--;
			printf("%c ", x);
		}
	}
	printf("\n");
}

void cari(queue *q){
	itemType z;
	int count;
	
	printf("%-25s", "Data yang dicari"); printf(": ");
	scanf("%c", &z);
	fflush(stdin);
	
	count = cekCari(z, q);
	
	if(count)
		printf("Data %c sebanyak %d", z, count);
	else
		printf("Data yang anda cari tidak ada");
	
	printf("\n");
}

itemType cekCari(itemType z, queue *q) {
	int i, j, y;
	itemType x;
	int count = 0;
	
	j = q->front;
	y = q->count;
	
	for(i=0; i<MAX; i++){
		if(y == 0)
			break;
		else {
			x = q->data[j];
			j = (j + 1) % MAX;
			y--;
			if(z == x)
				count++; 
		}
	}
	return(count);
}

void minMax(queue *q) {
	int i, j, y;
	itemType x;
	int min, max;
	
	j = q->front;
	y = q->count;
	
	for(i=0; i<MAX; i++){
		if(y == 0)
			break;
		else {
			x = q->data[j];
			j = (j + 1) % MAX;
			y--;
			
			if(i == 0){
				min = x;
				max = x;
			} else {
				if(x < min)
					min = x;
				
				if(x > max)
					max = x;	
			}
		}
	}
	
	printf("%-25s", "Nilai Min"); printf(": %c\n", min);
	printf("%-25s", "Nilai Max"); printf(": %c\n", max);
}

