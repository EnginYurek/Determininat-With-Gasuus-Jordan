/*YUREK,Engin

Student ID:040100524

Programming Assignment 1 */

#include<iostream>
#include<cmath>
#include<iomanip>
#define maximumSize  10
using std::cout;
using std::cin;
using std::endl;

void satirDegistir(double mainMatrix[maximumSize][maximumSize], int *satir, int *sutun, int *degisenSatirSay,int *a, int *k);
double detHesapala(double mainMatrix[maximumSize][maximumSize],int *k, int *degisenSatirSay);
void writeMatrix(double mainMatrix[maximumSize][maximumSize], int *k);
void sutunSifirlama(double mainMatrix[maximumSize][maximumSize], int *satir, int *sutun,int *k);
//program boyunca for yapýlarý içinde tanýmlanan tüm i deðiþkenleri satýrý tüm j deðiþkenleri sütunu temsil etmektedir
int main(){

	double mainMatrix[maximumSize][maximumSize] = { 0 };
	double   ilksatir[maximumSize] = { 0 };
	int satir = 0, sutun = 0, degisenSatirSay = 0;
	char c;				
	int k = 0; //dizinin sutun sayisini dizinin ilk satiri girildiði zaman bize verecek 
	/*(Maxsize kullanan fonklara bunun adresini deðiþken olarak gönder ve maxsize yerine herseferinde k yaz ve k yý hiçbiryerde deðiþtirme)*/

cout<<" Input the n-by-n matrix A by rows with a blank "<<endl
<<"between each element and a line between each row."<<endl<<endl;

	for (int b = 0; b <= maximumSize; b++){
		c = cin.peek();

		if (c != '\n'){
			cin >> ilksatir[b];
			k++;
		}
		else
			break;
	}
	
	for (int b = 0; b <= k - 1; b++)
		mainMatrix[0][b] = ilksatir[b];

	for (int b = 1; b <= k - 1; b++)
	for (int n = 0; n <= k - 1; n++)
		cin >> mainMatrix[b][n];
	cout << endl<<endl;
	
	//cout << "kullanicinin girdiði matrix" << endl;
	//writeMatrix(mainMatrix,&k);		//ana matrixi ilk girilen haliyle yazdýr.
	 

	cout << endl;

	for (int t = 0; t <= k -2; t++){				//bu for yapýsýnýn her dönüþü için bir o sutunun sýfýrlanacak sayý degerleri sýfýrlanýyor.
	
		/*aþaðýdaki for döngüsü asal köþegen üzerindeki matris elemanlarý sýfýra eþitse, o anki satýrý bir alttakiyle deðiþtiriyor eger 
		eleman yine sýfýr oluyorsa 2 alttaki satýr ile deðiþtiriyor */
		for (int a = satir; a < k - 1; a++){		
			satirDegistir(mainMatrix, &satir, &sutun, &degisenSatirSay, &a,&k);
			//writeMatrix(mainMatrix);
		//	cout << endl;
		}
	sutunSifirlama(mainMatrix, &satir, &sutun,&k);
	//writeMatrix(mainMatrix,&k);
	satir++;		// bu arttýrýmlar sayesinde asal köþegen üzerinde saða ve aþaðý ilerliyoruz
	sutun++;
	
												}
	cout << "Determinant of the matrix A is=" << detHesapala(mainMatrix,&k,&degisenSatirSay)<< endl;
	
	fflush(stdin);
	getchar();
	return 0;
}


														

void writeMatrix(double mainMatrix[maximumSize][maximumSize], int *k){ //kullanýcýnýn girdiði matrisi yazdýrýyor.

	for (int i = 0; i <= *k - 1; i++){
		for (int j = 0; j <= *k - 1; j++){
			
			cout << mainMatrix[i][j]<<" ";
			

		}
		cout << endl;
	}

}


void sutunSifirlama(double mainMatrix[maximumSize][maximumSize], int *satir, int *sutun, int *k){  

	int satirTut = *satir;  //main fonksiyonunda sutun sýfýrlama fonksiyonu her çaðýrýldýðýnda satir ve sutun pointerleri 1 er artýyor
	int sutunTut = *sutun;  //bu artýþ mýktarlarýný güncel olarak takip edebilmek için satirTut ve sutunTut deðiþkenleri atandý

	double refSatir[maximumSize] = {0};  /* sýfýrlama iþlemi yapýldýðýnda  sýfýrlama yapýlan satira eklenen referans satýrý temsil ediyor
											örneðin sutunSýfýrlama fonksiyonu ilk defa aðýrýldýðýnda refStari = ana fonksiyonun birinci satiri 
											ikinci çaðrýda ikinci satirina eþit olacak*/
	double m = mainMatrix[*satir + 1][*sutun]; //sýfýrlanma yapýlan satýrýn sýfýrlanacak elemanini tutuyor(satýrdaki tüm elemanlarý buna böleceðiz)
	
	for (sutunTut = *sutun; sutunTut <= *k-1; sutunTut++){    /*referans satir tanýmlandý. ilk çaðrý için ana fonksiyonun birinci satirina
																	   ikinci çaðrýda main fonksiyonu içinde satir ve sutun birer arttýrýldýðý için
																	   sutunSýfýrlama fonksiyonu ikinci kez çaðýrýldýðýnda refSatir ama fonksiyonun ikinci satýrýna eþit olur*/
		refSatir[sutunTut] = mainMatrix[*satir][sutunTut];
																	}
	
	for (int i = *satir; i <= *k - 1; i++){ 
		
		if (mainMatrix[i + 1][*sutun] == 0){		//sýfýrlanacak eleman zaten sýfýr ise o satýrý atlýyoruz
			m = mainMatrix[i + 2][*sutun];			//if komutu çalýþýrsa aþaðýdaki m = mainMatrix[i + 2][*sutun]; ifadesi çalýþmaz o yüzden buraya da ekledim ki her her zaman çalýþabilsin 
			continue;
		}
			for (int j = *sutun; j <= *k - 1; j++){ // sýfýrlanacak elemanýn bulunduðu satýrdaki deðer elemanlara da sýfýrlanan elemana uygulanan iþlemleri uyguluyor
				
				mainMatrix[i + 1][j] = ((mainMatrix[i + 1][j] / m)*-1 * refSatir[*satir]) + refSatir[j];

				
			}
			
			m = mainMatrix[i + 2][*sutun];
	}
	
}


double detHesapala(double mainMatrix[maximumSize][maximumSize], int *k, int *degisenSatirSay){

	double determinant = 1;
	int j = 0;
	for (int i = 0; i <= *k - 1; i++){
		
		determinant = determinant* mainMatrix[i][j];
		j++;
	}
	determinant = determinant*pow(-1, *degisenSatirSay);
	return determinant;
}

void satirDegistir(double mainMatrix[maximumSize][maximumSize], int *satir, int *sutun, int *degisenSatirSay, int *a, int *k){
	double tut;
	
		if (mainMatrix[*satir][*sutun] == 0){
			*degisenSatirSay+=1;			//determinant hesaplarken kullanýlacak pow(-1,degisenSatirSay)*determinant;
			
			for (int j = 0; j <= *k - 1; j++){
			tut = mainMatrix[*satir][j];
			mainMatrix[*satir][j] = mainMatrix[*a][j];
			mainMatrix[*a][j] = tut;
											}
												}

		
}


