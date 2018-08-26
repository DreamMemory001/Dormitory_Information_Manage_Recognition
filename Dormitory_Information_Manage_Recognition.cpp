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



  //全局变量
  int n = 0;
  struct  dormitory *head;
   
 //定义函数---------------------
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
	printf("请输入想要录入宿舍信息的人数："); 
	scanf("%d",&m) ;
	struct dormitory *p, *pt, *head;
	
	for(i = 0 ; i < m ; i++){
		
		p = (struct dormitory *)malloc (LEN);
		if ( i == 0 )
		head = pt = p;
		else
		pt -> next  = p ;
		pt = p;
		printf("姓名：" );
		scanf("%s", p -> name);
	
		
		printf("学号：" );
		scanf("%s", p -> stu_num);
	
		
		printf("宿舍号：" );
		scanf("%s", p -> dor_num);
		printf("\n");
		
		n++;
	}
	
	p -> next = NULL;
	
	return head;
}



//打印显示 
void print(struct dormitory *head){
	struct dormitory *p;
	p = head ;
	printf("\n姓名         学号           宿舍号\n");
	while(p != NULL){
		printf("%2s\t %6s\t %8s\t", p -> name, p -> stu_num , p -> dor_num);
		p = p -> next; 
		printf("\n");
	}	 
}

//添加信息
struct dormitory *insert(struct dormitory *head){
	struct dormitory *p1;
	p1 = (struct dormitory *) malloc (LEN);
	printf("请输入要添加学生的信息：\n");
	
		printf("姓名：" );
		scanf("%s", p1 -> name);
	
		
		printf("学号：" );
		scanf("%s", p1 -> stu_num);
	
		
		printf("宿舍号：" );
		scanf("%s", p1 -> dor_num);
		printf("\n");
		
	p1 -> next = head;
	head = p1 ;
	n++;
	return head;
		
}

//删除信息

struct dormitory *dele(struct dormitory *head){
	struct dormitory *p1 , *p2;
	char name[10];
	char fuction;
	printf("------输入要删除信息的人的姓名：-----：");
	scanf("%s", name);
	getchar();
	printf("------是否要继续进行该操作？( y / n)------");
	scanf("%c",&fuction);
	
	if(fuction == 'y'){
		if (head == NULL){
			printf("-------内存中没有任何信息，无法删除！！！----------");
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
			 
			 printf("---已经删除 %s 的信息", name);
			  	  
		n = n - 1;
		}
        else
		printf("---%s :没有此人的信息" , name);
	    return head;
	    
	}
	else
	    printf("---结束操作！！！"); 
}


//修改信息

void change(struct dormitory *head){
	struct dormitory *p = head;
	
	char name[10];
	char stu_num[10];
	char dor_num[10];
	
	printf("请输入要修改信息学生的姓名：");
	scanf("%s",name);
	if (strcmp(name, p -> name) == 0){
		printf("请输入修改后的信息：\n");
		printf("学号：");
		scanf("%s",stu_num);
		printf("宿舍号：");
		scanf("%s",dor_num);
		 
		strcpy(p -> stu_num ,stu_num);
		strcpy(p -> dor_num, dor_num);
		
	}
	else if(name != p -> name){
		printf("---请输入正确的姓名！！！"); 
	} 
} 

//按照学号进行排序
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
	printf("\n姓名         学号           宿舍号\n");
	for(t = head  ; t != NULL ; t = t -> next){
	   	printf( "%2s\t %6s\t %8s\t", t -> name , t -> stu_num , t -> dor_num );
		printf("\n");
	   }
			return head;
	}	
	
//按照宿舍号进行排序
struct dormitory *sort_dor_num(struct dormitory *head){
	struct dormitory *qi , *qj , *m;
	
	for(qi = head ; qi != NULL ; qi = qi -> next){
		for(qj = qi -> next ; qj != NULL ; qj = qj -> next){
			if((atoi( qi -> dor_num)) > (atoi(qj -> dor_num))){
				swap(qi, qj);
				
			}
		}
	}
		printf("\n姓名         学号           宿舍号\n");
	for(m = head  ; m != NULL ; m = m -> next){
	   	printf( "%2s\t %6s\t %8s\t",m -> name , m -> stu_num ,m -> dor_num );
		printf("\n");
	   }
			return head;
}

 //按照名字排序 
 
struct dormitory *sort_name(struct dormitory *head){
	struct dormitory *xi ,*xj , *y;
	
	for(xi = head ;xi != NULL; xi = xi -> next){
		for(xj = xi -> next ; xj != NULL ;xj = xj -> next){
			if(strcmp(xi -> name , xj -> name) > 0){
				swap(xi ,xj);
			}
		}
	}
		printf("\n姓名         学号           宿舍号\n");
		for(y = head  ; y != NULL ; y= y -> next){
	   	printf( "%2s\t %6s\t %8s\t",y -> name , y -> stu_num , y -> dor_num );
		printf("\n");
	   }
			return head;
	
}
 //按照姓名进行二分法查找 在查找之前 必须先排序 
 
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
	 
	printf("---请输入你想查询信息成员姓名：");
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
	printf("查询的结果为：");
	printf("\n");
	printf("\n姓名         学号           宿舍号\n");
	printf("%2s\t %6s\t %8s\t",name_str[t], stu_num_str[t], dor_num_str[t]); 
	printf("\n");
	
 } 
  
  

//按照学号进行 查询 在查询之前 必须 先进行 排序
 
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

    printf("---请输入你想查询信息成员的学号：");
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
 
  	printf("查询的结果为：");
	printf("\n");
	printf("\n姓名         学号           宿舍号\n");
	printf("%2s\t %6s\t %8s\t",name_str[a], stu_num_str[a], dor_num_str[a]); 
	printf("\n");
	

 
} 

//按照宿舍号进行查询 在使用二分法之前 应该 先进行 排序
 
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
	
	 
    printf("---请输入你想查询信息成员的宿舍号：");
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
	printf("查询的结果为：");
	printf("\n");
	printf("\n姓名         学号           宿舍号\n");
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
		printf("---抱歉，打开文件错误！！！");
		
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


//总菜单的选择 
void menu_select(){
	struct dormitorys *p;
	int flag ;
	FILE  *f;
	char t[] = "\r\n";
	char tishi_1[] = "---保存的信息如下："; 
	
    char tishi_2[] = "---删除之后的信息如下："; 
    char tishi_3[] = "---增加之后的信息如下："; 
    char tishi_4[] = "---修改之后的信息如下：";
     
	f = fopen(FILENAME, "ab+");
	if(f == NULL){
		printf("---出现文件错误");
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
						printf("------按任意键返回查找子菜单------"); 
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
						printf("------按任意键返回查找子菜单------"); 
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
			  printf("----谢谢使用-----");
			  exit(0);	    
		 }
		 printf("\n-------按任意键返回主菜单-------");
		 getchar(); 
	 }	
}



//父菜单 
int  fu_menu_select()
 {
	int fu_sel;
  	system("cls");               
  	printf("                           ############宿舍信息管理系统##############                                                          "); 
	printf("\n\n                                         [主菜单]              "); 
	printf("\n                               ￥|----------------------||\n");
	printf("\n                               ￥|**||1.宿舍信息录入    ||");
    printf("\n                               ￥|**||2.宿舍信息显示    ||");
	printf("\n                               ￥|**||3.宿舍信息查询    ||");
	printf("\n                               ￥|**||4.宿舍信息添加    ||");
	printf("\n                               ￥|**||5.宿舍信息删除    ||");
	printf("\n                               ￥|**||6.宿舍信息修改    ||"); 
	printf("\n                               ￥|**||0.退出系统        ||");
	printf("\n                               ￥|----------------------||\n");
	for( ; ; )
	{
		printf("\n----请选择（0-6）：");
		scanf("%d",&fu_sel) ;
		printf("\n");
		if(fu_sel < 0 || fu_sel > 6 )
		printf("----输入错误！！");
		else 
		break;
	} 
	    return fu_sel; 
}

//子菜单1 
int  zi_menu_select_1() 
{
	int zi_sel_1;
	system ("cls");
	printf("\n   [ 宿舍信息显示子菜单]    ");
	printf("\n------------------------\n");
	printf("\n**||1.按姓名排序显示    ||    \n");
	printf("\n**||2.按学号排序显示    ||    \n");
	printf("\n**||3.按宿舍号排序显示  ||    \n");
	printf("\n**||0.返回              ||    \n");
	printf("\n------------------------\n");
	for( ;  ; )
	{
    printf("\n 请选择（0-3）：");
	scanf ("%d",&zi_sel_1);
	printf("\n");
	if(zi_sel_1 < 0 || zi_sel_1 > 3 )
		{ 
			printf("----输入错误！！");
		} 
		  else 
		    { 
			    break;
		    } 
	}     
	return zi_sel_1;
}
	
//子菜单2
int  zi_menu_select_2() 
{
	int zi_sel_2;
	system ("cls");
	printf("\n   [ 宿舍信息查找子菜单]    ");
	printf("\n------------------------\n");
	printf("\n**||1.按姓名查询        ||    \n");
	printf("\n**||2.按学号查询        ||    \n");
	printf("\n**||3.按宿舍号查询      ||    \n");
	printf("\n**||0.返回              ||    \n");
	printf("\n------------------------\n");
	for( ;  ; )
	{
    printf("\n 请选择（0-3）：");
	scanf ("%d",&zi_sel_2);
	printf("\n");
	if(zi_sel_2 < 0 || zi_sel_2 > 3 )
		{ 
			printf("----输入错误！！");
		} 
		  else 
		    { 
			    break;
		    } 
	} 
	    return zi_sel_2;
}
