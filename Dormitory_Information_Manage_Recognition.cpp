#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>

using namespace std;
#define N 100
#define LEN sizeof (struct dormitory)
#define FILENAME ("E:\\dormitory.txt")
struct dormitory{
	
	char name[20];
	char stu_num[10];
	char dor_num[10];
	struct  dormitory *next;
};



  //ȫ�ֱ���
  int n = 0;
  struct  dormitory *head;
   
 //���庯��---------------------
int  fu_menu_select(); 
int  zi_menu_select_1();
int  zi_menu_select_2();
void menu_select();
struct dormitory *create ();
void save(struct dormitory *head);
void print (struct dormitory *head);
struct dormitory *insert(struct dormitory *head);
struct dormitory *dele(struct dormitory *head); 
void change(struct dormitory *head);
void swap(struct dormitory *p1, struct dormitory *p2);
struct dormitory *sort_stu_num(struct dormitory *head);
struct dormitory *sort_name(struct dormitory *head);
struct dormitory *sort_dor_num(struct dormitory *head);
void search_name(struct dormitory *head);
void search_stu_num(struct dormitory *head);
void search_dor_num(struct dormitory *head);
 //----------------------------------------
 
 
 
 int main(){
 	menu_select();
 	return 0;
 } 





struct  dormitory *create(){
	int i ;
	int m;
	printf("��������Ҫ¼��������Ϣ��������"); 
	scanf("%d",&m) ;
	struct dormitory *p, *pt, *head;
	
	for(i = 0 ; i < m ; i++){
		
		p = (struct dormitory *)malloc (LEN);
		if ( i == 0 )
		head = pt = p;
		else
		pt -> next  = p ;
		pt = p;
		printf("������" );
		scanf("%s", p -> name);
	
		
		printf("ѧ�ţ�" );
		scanf("%s", p -> stu_num);
	
		
		printf("����ţ�" );
		scanf("%s", p -> dor_num);
		printf("\n");
		
		n++;
	}
	
	p -> next = NULL;
	
	return head;
}



//��ӡ��ʾ 
void print(struct dormitory *head){
	struct dormitory *p;
	p = head ;
	printf("\n����         ѧ��           �����\n");
	while(p != NULL){
		printf("%2s\t %6s\t %8s\t", p -> name, p -> stu_num , p -> dor_num);
		p = p -> next; 
		printf("\n");
	}	 
}

//�����Ϣ
struct dormitory *insert(struct dormitory *head){
	struct dormitory *p1;
	p1 = (struct dormitory *) malloc (LEN);
	printf("������Ҫ���ѧ������Ϣ��\n");
	
		printf("������" );
		scanf("%s", p1 -> name);
	
		
		printf("ѧ�ţ�" );
		scanf("%s", p1 -> stu_num);
	
		
		printf("����ţ�" );
		scanf("%s", p1 -> dor_num);
		printf("\n");
		
	p1 -> next = head;
	head = p1 ;
	n++;
	return head;
		
}

//ɾ����Ϣ

struct dormitory *dele(struct dormitory *head){
	struct dormitory *p1 , *p2;
	char name[10];
	char fuction;
	printf("------����Ҫɾ����Ϣ���˵�������-----��");
	scanf("%s", name);
	getchar();
	printf("------�Ƿ�Ҫ�������иò�����( y / n)------");
	scanf("%c",&fuction);
	
	if(fuction == 'y'){
		if (head == NULL){
			printf("-------�ڴ���û���κ���Ϣ���޷�ɾ��������----------");
			return head;
		}
		
		p1 = head;
		while(strcmp(name, p1 -> name ) != 0 && p1 -> next != NULL){
			p2 = p1;
			p1 = p1 -> next;
		}
		
		if (strcmp(name, p1 -> name) == 0 ){
			if(p1 ==head)
			  head = p1 ->next ;
			
			else 
			 p2 -> next = p1 -> next ;
			 
			 printf("---�Ѿ�ɾ�� %s ����Ϣ", name);
			  	  
		n = n - 1;
		}
        else
		printf("---%s :û�д��˵���Ϣ" , name);
	    return head;
	    
	}
	else
	    printf("---��������������"); 
}


//�޸���Ϣ

void change(struct dormitory *head){
	struct dormitory *p = head;
	
	char name[10];
	char stu_num[10];
	char dor_num[10];
	
	printf("������Ҫ�޸���Ϣѧ����������");
	scanf("%s",name);
	if (strcmp(name, p -> name) == 0){
		printf("�������޸ĺ����Ϣ��\n");
		printf("ѧ�ţ�");
		scanf("%s",stu_num);
		printf("����ţ�");
		scanf("%s",dor_num);
		 
		strcpy(p -> stu_num ,stu_num);
		strcpy(p -> dor_num, dor_num);
		
	}
	else if(name != p -> name){
		printf("---��������ȷ������������"); 
	} 
} 

//����ѧ�Ž�������
struct dormitory *sort_stu_num(struct dormitory *head){
	
	int i ;
	struct dormitory *pi, *pj, *t;
	
	for(pi = head  ; pi != NULL; pi = pi -> next){
		for(pj = pi -> next; pj != NULL; pj = pj -> next){
			if((atoi(pi -> stu_num)) > (atoi(pj -> stu_num))){
				swap(pi ,pj); 
			}
		}
	}
	printf("\n����         ѧ��           �����\n");
	for(t = head  ; t != NULL ; t = t -> next){
	   	printf( "%2s\t %6s\t %8s\t", t -> name , t -> stu_num , t -> dor_num );
		printf("\n");
	   }
			return head;
	}	
	
//��������Ž�������
struct dormitory *sort_dor_num(struct dormitory *head){
	struct dormitory *qi , *qj , *m;
	
	for(qi = head ; qi != NULL ; qi = qi -> next){
		for(qj = qi -> next ; qj != NULL ; qj = qj -> next){
			if((atoi( qi -> dor_num)) > (atoi(qj -> dor_num))){
				swap(qi, qj);
				
			}
		}
	}
		printf("\n����         ѧ��           �����\n");
	for(m = head  ; m != NULL ; m = m -> next){
	   	printf( "%2s\t %6s\t %8s\t",m -> name , m -> stu_num ,m -> dor_num );
		printf("\n");
	   }
			return head;
}

 //������������ 
 
struct dormitory *sort_name(struct dormitory *head){
	struct dormitory *xi ,*xj , *y;
	
	for(xi = head ;xi != NULL; xi = xi -> next){
		for(xj = xi -> next ; xj != NULL ;xj = xj -> next){
			if(strcmp(xi -> name , xj -> name) > 0){
				swap(xi ,xj);
			}
		}
	}
		printf("\n����         ѧ��           �����\n");
		for(y = head  ; y != NULL ; y= y -> next){
	   	printf( "%2s\t %6s\t %8s\t",y -> name , y -> stu_num , y -> dor_num );
		printf("\n");
	   }
			return head;
	
}
 //�����������ж��ַ����� �ڲ���֮ǰ ���������� 
 
 void search_name(struct dormitory *head){
 	struct dormitory  *p;
 	int i = 0 ;
 	int left  = 0 ;
 	int right = n - 1;
 	int mid ;
 	int t;
 	
 	char *name_str[n] ;
 	char *stu_num_str[n];
 	char *dor_num_str[n];
 	char *temp;
 	char search_name[10];
	
	struct dormitory *xi ,*xj , *y;
	for(xi = head ;xi != NULL; xi = xi -> next){
		for(xj = xi -> next ; xj != NULL ;xj = xj -> next){
			if(strcmp(xi -> name , xj -> name) > 0){
				swap(xi ,xj);
			}
		}
	}
	p = head;
	while(p != NULL){
	 	name_str[i] = p -> name;
	 	stu_num_str[i] = p -> stu_num;
	 	dor_num_str[i] = p -> dor_num;
	 	i++;
	 	p = p -> next;
	 }
	 
	printf("---�����������ѯ��Ϣ��Ա������");
	scanf("%s", search_name); 
	printf("\n");
	 
	while(left <= right ){
		mid = (left + right )/2 ;

		if(strcmp(search_name, name_str[mid]) < 0){
			right = mid  - 1;
		
			
		} 
		else if(strcmp(search_name, name_str[mid]) > 0){	
			left = mid + 1;
		}
		else{
		   t = mid;
		   break;
		}
	
	}
	printf("��ѯ�Ľ��Ϊ��");
	printf("\n");
	printf("\n����         ѧ��           �����\n");
	printf("%2s\t %6s\t %8s\t",name_str[t], stu_num_str[t], dor_num_str[t]); 
	printf("\n");
	
 } 
  
  

//����ѧ�Ž��� ��ѯ �ڲ�ѯ֮ǰ ���� �Ƚ��� ����
 
void search_stu_num(struct dormitory *head){
     struct dormitory *q ;
     int j = 0 ;
     int l = 0 ;
     int r = n - 1;
     int m ;
     int a = 0;
	 
	 char *name_str[n];
	 char *stu_num_str[n];
	 char *dor_num_str[n];
	 char search_stu_num[10];
	 struct dormitory *pi, *pj;
 
 for(pi = head  ; pi != NULL; pi = pi -> next){
   for(pj = pi -> next; pj != NULL; pj = pj -> next){
     if( strcmp(pi -> stu_num, pj -> stu_num) > 0){
       swap(pi ,pj); 
     }
   }
 }
 
    q = head;
    while(q != NULL){
	 	name_str[j] = q -> name;
	 	stu_num_str[j] = q -> stu_num;
		dor_num_str[j] = q -> dor_num;
	 	j++;
	 	q= q-> next;
	 }

    printf("---�����������ѯ��Ϣ��Ա��ѧ�ţ�");
    scanf("%s", search_stu_num); 
    printf("\n");
 
   while(l <= r ){
      m = (l + r )/2 ;

     if( strcmp(search_stu_num , stu_num_str[m]) > 0){
        l= m + 1 ;
     
     } 
     else if( strcmp(search_stu_num , stu_num_str[m])  < 0){
       r = m  - 1;
     }
      else{
      a = m;
      break;
   }
 }
 
  	printf("��ѯ�Ľ��Ϊ��");
	printf("\n");
	printf("\n����         ѧ��           �����\n");
	printf("%2s\t %6s\t %8s\t",name_str[a], stu_num_str[a], dor_num_str[a]); 
	printf("\n");
	

 
} 

//��������Ž��в�ѯ ��ʹ�ö��ַ�֮ǰ Ӧ�� �Ƚ��� ����
 
void search_dor_num(struct dormitory *head){
		struct dormitory *p;
	int i = 0;
	int left  = 0 ;
	int right = n -1;
	int mid ;
	int t;
	
	char *name_str[n] ;
    char *stu_num_str[n];
    char *dor_num_str[n];
    char *temp;
    char search_dor_num[10]; 
    struct dormitory *qi , *qj , *m;
	
	for(qi = head ; qi != NULL ; qi = qi -> next){
		for(qj = qi -> next ; qj != NULL ; qj = qj -> next){
			if((atoi( qi -> dor_num)) > (atoi(qj -> dor_num))){
				swap(qi, qj);
				
			}
		}
	}
	
	p = head;
	while(p != NULL){
	 	name_str[i] = p -> name;
	 	stu_num_str[i] = p -> stu_num;
	 		dor_num_str[i] = p -> dor_num;
	 	i++;
	 	p = p -> next;
	 }
	
	 
    printf("---�����������ѯ��Ϣ��Ա������ţ�");
	scanf("%s", search_dor_num); 
	printf("\n");
	
	while(left <= right ){
		mid = (left + right )/2 ;

		if(strcmp(search_dor_num, dor_num_str[mid]) > 0){
			left = mid + 1;
			
		} 
		else if(strcmp(search_dor_num, dor_num_str[mid]) < 0){
			right = mid  - 1;
		}
		else{
		   t = mid;
		   break;
		}
	}
	printf("��ѯ�Ľ��Ϊ��");
	printf("\n");
	printf("\n����         ѧ��           �����\n");
	printf("%2s\t %6s\t %8s\t",name_str[t], stu_num_str[t], dor_num_str[t]); 
	printf("\n");	 
    
}
 
void save(struct dormitory *head){
	char str[] = "      ";
	char h[] = "\r\n";
	FILE *fp;
	struct dormitory *p;

	fp = fopen(FILENAME,"ab+");
	p = head ;
	if(fp == NULL){
		printf("---��Ǹ�����ļ����󣡣���");
		
	} 
	while( p != NULL){
		fwrite( p -> name, strlen(p -> name), 1 , fp);
		fwrite(str, strlen(str), 1, fp);
		
		fwrite( p -> stu_num, strlen(p -> stu_num) , 1 , fp);
		fwrite(str, strlen(str), 1, fp);
	
		fwrite( p -> dor_num, strlen(p -> dor_num), 1 , fp);
	    fwrite(str, strlen(str), 1, fp);
		 
		fwrite(h,strlen(h), 1 , fp); 
	   
		p = p -> next;
	
	} 
	fclose(fp);
	fp = NULL;
}

void swap(struct dormitory *p1, struct dormitory *p2){
	struct dormitory t;
	
	strcpy(t.name, p1 -> name);
	strcpy(p1 -> name, p2 -> name);
	strcpy(p2 -> name, t.name);
	
	strcpy(t.stu_num, p1 -> stu_num);
	strcpy(p1 ->stu_num, p2 -> stu_num);
	strcpy(p2 -> stu_num, t.stu_num);
	
	strcpy(t.dor_num, p1 ->dor_num);
	strcpy(p1 -> dor_num, p2 ->dor_num);
	strcpy(p2 -> dor_num, t.dor_num);
	 
}


//�ܲ˵���ѡ�� 
void menu_select(){
	struct dormitorys *p;
	int flag ;
	FILE  *f;
	char t[] = "\r\n";
	char tishi_1[] = "---�������Ϣ���£�"; 
	
    char tishi_2[] = "---ɾ��֮�����Ϣ���£�"; 
    char tishi_3[] = "---����֮�����Ϣ���£�"; 
    char tishi_4[] = "---�޸�֮�����Ϣ���£�";
     
	f = fopen(FILENAME, "ab+");
	if(f == NULL){
		printf("---�����ļ�����");
	} 
     while(1){
     	switch(fu_menu_select()){
     		case 1:
     			 fwrite(tishi_1, strlen(tishi_1), 1 , f);
     		     fwrite(t, strlen(t), 1 , f);
     		     head = create();
     		     print(head);
     		     save(head);
     			 system("pause");
				break;
		    case 2 :
		    flag = 1;
			    while(flag){
			    	switch(zi_menu_select_1()){
			    		case 1:
			    			head = sort_name(head);
			    			system("pause");
			    			break;
			    		case 2:
			    		    head = sort_stu_num(head);
			    			system("pause");
			    			break;
			    	    case 3:
			    	    	head = sort_dor_num(head);
			    	    	system("pause");
			    			break;
			    		case 0:
			    			flag = 0;
			    			break;
					}
					if(flag == 1){
						printf("------����������ز����Ӳ˵�------"); 
						getchar();	
					}
				}
			    break;
		    case 3 :
		    	 flag = 1;
			    while(flag){
			    	switch(zi_menu_select_2()){
			    		case 1:
			    			search_name(head);
			    			system("pause");
			    			break;
			    		case 2:
			    		    search_stu_num(head);
			    			system("pause");
			    			break;
			    	    case 3:
			    	    	search_dor_num(head);
			    	    	system("pause");
			    			break;
			    		case 0:
			    			flag = 0;
			    			break;
					}
					if(flag == 1){
						printf("------����������ز����Ӳ˵�------"); 
						getchar();	
					}
				}
		    	system("pause");
			    break;
			case 4 :
				fwrite(tishi_3, strlen(tishi_3) , 1 , f);
			    fwrite(t, strlen(t), 1 , f);
			    head = insert(head); 
			    print(head);
			    save(head);
			    system("pause");
			    break;
		    case 5 :
		    	 fwrite(tishi_2, strlen(tishi_2) , 1 , f);
		        fwrite(t, strlen(t), 1 , f);
		        head = dele(head);
		        print(head);
		        save(head);
		        system("pause");
			    break;
			case 6:
				fwrite(tishi_4, strlen(tishi_4) , 1 , f);
		        fwrite(t, strlen(t), 1 , f);
		        
			    change(head);
			    print(head);
			    save(head);
			    system("pause");
			    break;						
		
			case 0:
			  printf("----ллʹ��-----");
			  exit(0);	    
		 }
		 printf("\n-------��������������˵�-------");
		 getchar(); 
	 }	
}



//���˵� 
int  fu_menu_select()
 {
	int fu_sel;
  	system("cls");               
  	printf("                           ############������Ϣ����ϵͳ##############                                                          "); 
	printf("\n\n                                         [���˵�]              "); 
	printf("\n                               ��|----------------------||\n");
	printf("\n                               ��|**||1.������Ϣ¼��    ||");
    printf("\n                               ��|**||2.������Ϣ��ʾ    ||");
	printf("\n                               ��|**||3.������Ϣ��ѯ    ||");
	printf("\n                               ��|**||4.������Ϣ���    ||");
	printf("\n                               ��|**||5.������Ϣɾ��    ||");
	printf("\n                               ��|**||6.������Ϣ�޸�    ||"); 
	printf("\n                               ��|**||0.�˳�ϵͳ        ||");
	printf("\n                               ��|----------------------||\n");
	for( ; ; )
	{
		printf("\n----��ѡ��0-6����");
		scanf("%d",&fu_sel) ;
		printf("\n");
		if(fu_sel < 0 || fu_sel > 6 )
		printf("----������󣡣�");
		else 
		break;
	} 
	    return fu_sel; 
}

//�Ӳ˵�1 
int  zi_menu_select_1() 
{
	int zi_sel_1;
	system ("cls");
	printf("\n   [ ������Ϣ��ʾ�Ӳ˵�]    ");
	printf("\n------------------------\n");
	printf("\n**||1.������������ʾ    ||    \n");
	printf("\n**||2.��ѧ��������ʾ    ||    \n");
	printf("\n**||3.�������������ʾ  ||    \n");
	printf("\n**||0.����              ||    \n");
	printf("\n------------------------\n");
	for( ;  ; )
	{
    printf("\n ��ѡ��0-3����");
	scanf ("%d",&zi_sel_1);
	printf("\n");
	if(zi_sel_1 < 0 || zi_sel_1 > 3 )
		{ 
			printf("----������󣡣�");
		} 
		  else 
		    { 
			    break;
		    } 
	}     
	return zi_sel_1;
}
	
//�Ӳ˵�2
int  zi_menu_select_2() 
{
	int zi_sel_2;
	system ("cls");
	printf("\n   [ ������Ϣ�����Ӳ˵�]    ");
	printf("\n------------------------\n");
	printf("\n**||1.��������ѯ        ||    \n");
	printf("\n**||2.��ѧ�Ų�ѯ        ||    \n");
	printf("\n**||3.������Ų�ѯ      ||    \n");
	printf("\n**||0.����              ||    \n");
	printf("\n------------------------\n");
	for( ;  ; )
	{
    printf("\n ��ѡ��0-3����");
	scanf ("%d",&zi_sel_2);
	printf("\n");
	if(zi_sel_2 < 0 || zi_sel_2 > 3 )
		{ 
			printf("----������󣡣�");
		} 
		  else 
		    { 
			    break;
		    } 
	} 
	    return zi_sel_2;
}
