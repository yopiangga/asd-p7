#include <stdio.h>
#include <stdlib.h>

typedef struct element Node;
struct element {
	int data;
	int prioritas;
	Node *next;
};

Node *rear, *front, *p;

void enqueue();
int dequeue();

void inserBefore();

void initialisasi();
void alokasi();

void tambah();
void ambil();
void tampil();

void insert();
void akhir();
void insertPertama();
void insertTerakhir();
void insertAntara();

void menu();

int pilihan;

int main(){
	initialisasi();
	
	do
		menu();
	while(pilihan != 4);
}

void menu(){
	printf("========================\n");
	printf(" Menu Queue SLL\n");
	printf("========================\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Cetak Data\n");
	printf("4. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihan);
	fflush(stdin);
	
	if(front == NULL && pilihan >= 2 && pilihan <= 3)
		printf("Data masih kosong gan :)\n");
	else {
		switch(pilihan){
			case 1:
				tambah();
				break;
			case 2:
				ambil();
				break;
			case 3:
				tampil();
				break;
		}
	}
	
}


void initialisasi(){
	front = NULL;
	rear = NULL;
}

void alokasi(){
	int x, prioritas;
	
	printf("%-25s", "Masukkan data "); printf(": ");
	scanf("%c", &x);
	fflush(stdin);
	printf("%-25s", "Masukkan Prioritas "); printf(": ");
	scanf("%d", &prioritas);
	fflush(stdin);
	
	p = (Node *) malloc(sizeof(Node));
	
	if(p ==NULL){
		printf("Alokasi memori gagal");
		exit(0);
	}
	
	p->data = x;
	p->prioritas = prioritas;
	p->next = NULL;
}

void tambah(){
	alokasi();
	
	insert();
}

void insert(){
	int tail;
		tail = Akhir();
	if(front == NULL)
		front = p;
	else {
		if(p->prioritas < front->prioritas)
			insertPertama();
		else if(p->prioritas >= tail)
			insertTerakhir();
		else 
			insertAntara();
	}
}

int Akhir(){
	Node *jalan;
	int tail;
	jalan = front;
	if(front == NULL)
		tail = 0;
	else {
		while(jalan != NULL){
			tail = jalan->prioritas;
			jalan= jalan->next;
		}
	}
	return tail;
}

void insertPertama(){
	p->next = front;
	front = p;
}

void insertTerakhir(){
	Node *jalan;
	jalan = front;
	while(jalan->next != NULL)
		jalan = jalan->next;
	jalan->next = p;
}

void insertAntara(){
	Node *jalan, *pjalan;
	int nodeAfter;
	Node *bp;
	jalan = front;
	while(p->prioritas >= jalan->prioritas){
		pjalan = jalan;
		jalan = jalan->next;
	}
	nodeAfter = jalan->prioritas;
	
	jalan = front;
	while(jalan->prioritas != nodeAfter){
		if(jalan == NULL){
			printf("Data yang anda cari tidak ada");
			exit(0);
		}
		bp = jalan;
		jalan = jalan->next;
	}
	p->next = bp->next;
	bp->next = p;
}


void ambil(){
	printf("%c \n", dequeue());
}

int dequeue() {
	int x;
	
	if(front == NULL){
		printf("stack kosong, tidak ada data ");
		return(0);
	} else {
		x = front->data;
		front = front->next;
		return(x);	
	}
}

void tampil(){
	Node *jalan;
	jalan = front;
	printf("%-7s", "Data"); printf("%-7s", "Prioritas"); printf("\n");
	while(jalan != NULL){
		printf("%-7c", jalan->data); printf("%-7d", jalan->prioritas); printf("\n");
		jalan = jalan->next;
	}
	printf("\n");
}

