#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void Hesh_str(int y, char str_f2[5], char str_1[200] ) { // Робин-Карп
     int h=0, g=0, l=0, p=0;
     int q, k, r, u, w;
     
     q=strlen(str_f2);
     for(int i=0;i<q;i++) h=h+char(str_f2[i]);
     
     for(int i=0;i<(y-q);i++) {
             l++; k=0;
             g=0; r=i;
             do {
                 g=g+char(str_1[r]);
                 r++; k++;
                 } while(k!=q);
     
     if(g==h) {
              k=0; w=0;
              u=0; r=i;
              do {
                  if(char(str_f2[u])==char(str_1[r])) w++;
                  k++; w++;
                  u++; r++;
                  } while(k!=q);
              if(u==4) {
                       printf("Искомое слово было найдено в тексте, за %d шаг(а/ов)!", l);
                       p++; break;
                       }; };
              };
     if(p==0) printf("!!!Искомое слово не было найдено в тексте!!!");  
     }

void KMP(int y, char str_f3[5], char str_2[200]) { // Кнута-Морриса-Пратта
     int s=0, l=0, p=0;
     int a, d, e, j, r, k, i;
     
     a=strlen(str_f3);
     
     for(i=0;i<y;i++) {
             l++; e=0;
             j=0; s=0;
             if(char(str_2[i])==char(str_f3[e])) {
                                s++; j++;
                                r=i; k=e;
                                do {
                                   r++; k++;
                                   if(char(str_2[r])==char(str_f3[k])) { j++; s++; }
                                   else {
                                        j++; i=i+j;
                                        break;
                                        };
                                   if(s==4){
                                            printf("Искомое слово было найдено в тексте, за %d шаг(а/ов)!", l);
                                            p++; break;
                                            };
                                   } while(k!=e);
                                };
                                };
     if(p==0) printf("!!!Искомое слово не было найдено в тексте!!!");  
}

void BM(int y, char str_f4[5], char str_3[200]) { // Бойер-Мур
     int l=0, p=0;
     int a, e, r, s, j, k;
     
     a=strlen(str_f4);
     
     for(int i=(a-1);i<y;i++) {
            l++; 
            e=(a-1); r=i; 
            s=0; j=0;
            if(char(str_3[r])==char(str_f4[e])) {
                    e--; r--;
                    s++; j++;
                    k=a;
                    do {
                        k--;
                        if(char(str_3[r])==char(str_f4[e])) { j++; s++;}
                        else {
                             j++; i=i+j;
                             break; };
                        r--; 
                        e--;
                            if(s==4){
                                     printf("Искомое слово было найдено в тексте, за %d шаг(а/ов)!\n", l);
                                     p++; break;
                                     };
                        } while(k!=0);
                    };
                    j++;
                    i=i+j;};
     if(p==0) printf("!!!Искомое слово не было найдено в тексте!!!\n");                               
     }

int main() {
    char str[200]="наука не является и никогда не будет являться законченной книгой. каждый важный успех приносит новые вопросы. всякое развитие обнаруживает со временем все новые и более глубокие трудности. \n Эйнштейн";
    char str_f1[5]="труд";
    int p=0, int_x=0;
    int x, m;
    
    printf("\nИсходный текст: \n\n");
    printf("%s", str);
    
    printf("\n\nПример поиска в тексте cлова - 'труд' ");
    
    printf("\n\nПоиск подстроки в тексте, при помощи 'наивного' алгоритма:\n");
    p=0;
    int_x=0;
    m=strlen(str);
    for( int i=0;i<m;i++) {
         int_x++;
         if(char(str[i])==char(str_f1[0])) {
            if(char(str[i+1])==char(str_f1[1]) && char(str[i+2])==char(str_f1[2]) && char(str[i+3])==char(str_f1[3])) {
                 p++;
                 break; };
                 }
         };
    if(p!=0) printf("Искомое слово было найдено в тексте, за %d шаг(а/ов)!", int_x);
    else printf("!!!Искомое слово не было найдено в тексте!!!");
    
    printf("\n\nПоиск подстроки в тексте, при помощи алгоритма Рабина-Карпа:\n");
    x=strlen(str);
    Hesh_str(x,str_f1, str);
    
    printf("\n\nПоиск подстроки в тексте, при помощи алгоритма Кнута-Морриса-Пратта:\n");
    KMP(x, str_f1, str);
    
    printf("\n\nПоиск подстроки в тексте, при помощи алгоритма Бойера-Мура:\n");
    BM(x, str_f1, str);
        
printf("\nДля завершения программы нажмите Enter ...");   
getch();
return 1;
}
