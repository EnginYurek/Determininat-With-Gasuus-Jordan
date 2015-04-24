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
//program boyunca for yap�lar� i�inde tan�mlanan t�m i de�i�kenleri sat�r� t�m j de�i�kenleri s�tunu temsil etmektedir
int main(){

	double mainMatrix[maximumSize][maximumSize] = { 0 };
	double   ilksatir[maximumSize] = { 0 };
	int satir = 0, sutun = 0, degisenSatirSay = 0;
	char c;				
	int k = 0; //dizinin sutun sayisini dizinin ilk satiri girildi�i zaman bize verecek 
	/*(Maxsize kullanan fonklara bunun adresini de�i�ken olarak g�nder ve maxsize yerine herseferinde k yaz ve k y� hi�biryerde de�i�tirme)*/

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
	
	//cout << "kullanicinin girdi�i matrix" << endl;
	//writeMatrix(mainMatrix,&k);		//ana matrixi ilk girilen haliyle yazd�r.
	 

	cout << endl;

	for (int t = 0; t <= k -2; t++){				//bu for yap�s�n�n her d�n��� i�in bir o sutunun s�f�rlanacak say� degerleri s�f�rlan�yor.
	
		/*a�a��daki for d�ng�s� asal k��egen �zerindeki matris elemanlar� s�f�ra e�itse, o anki sat�r� bir alttakiyle de�i�tiriyor eger 
		eleman yine s�f�r oluyorsa 2 alttaki sat�r ile de�i�tiriyor */
		for (int a = satir; a < k - 1; a++){		
			satirDegistir(mainMatrix, &satir, &sutun, &degisenSatirSay, &a,&k);
			//writeMatrix(mainMatrix);
		//	cout << endl;
		}
	sutunSifirlama(mainMatrix, &satir, &sutun,&k);
	//writeMatrix(mainMatrix,&k);
	satir++;		// bu artt�r�mlar sayesinde asal k��egen �zerinde sa�a ve a�a�� ilerliyoruz
	sutun++;
	
												}
	cout << "Determinant of the matrix A is=" << detHesapala(mainMatrix,&k,&degisenSatirSay)<< endl;
	
	fflush(stdin);
	getchar();
	return 0;
}


														

void writeMatrix(double mainMatrix[maximumSize][maximumSize], int *k){ //kullan�c�n�n girdi�i matrisi yazd�r�yor.

	for (int i = 0; i <= *k - 1; i++){
		for (int j = 0; j <= *k - 1; j++){
			
			cout << mainMatrix[i][j]<<" ";
			

		}
		cout << endl;
	}

}


void sutunSifirlama(double mainMatrix[maximumSize][maximumSize], int *satir, int *sutun, int *k){  

	int satirTut = *satir;  //main fonksiyonunda sutun s�f�rlama fonksiyonu her �a��r�ld���nda satir ve sutun pointerleri 1 er art�yor
	int sutunTut = *sutun;  //bu art�� m�ktarlar�n� g�ncel olarak takip edebilmek i�in satirTut ve sutunTut de�i�kenleri atand�

	double refSatir[maximumSize] = {0};  /* s�f�rlama i�lemi yap�ld���nda  s�f�rlama yap�lan satira eklenen referans sat�r� temsil ediyor
											�rne�in sutunS�f�rlama fonksiyonu ilk defa a��r�ld���nda refStari = ana fonksiyonun birinci satiri 
											ikinci �a�r�da ikinci satirina e�it olacak*/
	double m = mainMatrix[*satir + 1][*sutun]; //s�f�rlanma yap�lan sat�r�n s�f�rlanacak elemanini tutuyor(sat�rdaki t�m elemanlar� buna b�lece�iz)
	
	for (sutunTut = *sutun; sutunTut <= *k-1; sutunTut++){    /*referans satir tan�mland�. ilk �a�r� i�in ana fonksiyonun birinci satirina
																	   ikinci �a�r�da main fonksiyonu i�inde satir ve sutun birer artt�r�ld��� i�in
																	   sutunS�f�rlama fonksiyonu ikinci kez �a��r�ld���nda refSatir ama fonksiyonun ikinci sat�r�na e�it olur*/
		refSatir[sutunTut] = mainMatrix[*satir][sutunTut];
																	}
	
	for (int i = *satir; i <= *k - 1; i++){ 
		
		if (mainMatrix[i + 1][*sutun] == 0){		//s�f�rlanacak eleman zaten s�f�r ise o sat�r� atl�yoruz
			m = mainMatrix[i + 2][*sutun];			//if komutu �al���rsa a�a��daki m = mainMatrix[i + 2][*sutun]; ifadesi �al��maz o y�zden buraya da ekledim ki her her zaman �al��abilsin 
			continue;
		}
			for (int j = *sutun; j <= *k - 1; j++){ // s�f�rlanacak eleman�n bulundu�u sat�rdaki de�er elemanlara da s�f�rlanan elemana uygulanan i�lemleri uyguluyor
				
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
			*degisenSatirSay+=1;			//determinant hesaplarken kullan�lacak pow(-1,degisenSatirSay)*determinant;
			
			for (int j = 0; j <= *k - 1; j++){
			tut = mainMatrix[*satir][j];
			mainMatrix[*satir][j] = mainMatrix[*a][j];
			mainMatrix[*a][j] = tut;
											}
												}

		
}


