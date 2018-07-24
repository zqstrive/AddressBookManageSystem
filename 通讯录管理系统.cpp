#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<conio.h>
#include<windows.h>
#define MAX_PERSON_NUM 30  /*定义最多人数*/ 
 
typedef struct address		/*定义联系人相关信息*/ 
{
	int no;
	char name[15];
	char phone[15];
	char qq[15];
}Tel;
int Menu();					/*选择菜单*/ 						/* *n 传址 联系人个数可以在各个函数更改*/ 
void InputRecord(Tel tel[],int *n); 	/*初始化输入函数*/ 
void DisplayRecord(Tel tel[],int *n);	/*显示函数*/ 	
void DeleteRecord(Tel tel[],int *n);	/*删除函数*/ 
void SearchRecord(Tel tel[],int *n);	/*查询函数*/ 
void ModifyRecord(Tel tel[],int *n);	/*修改函数*/ 
void ModifyInputRecord(Tel tel[],int j);	/*修改后信息输出函数*/ 
void InsertRecord(Tel tel[],int *n);	/*插入函数*/ 
void SortRecord(Tel tel[],int *n);		/*排序函数*/ 
void SaveRecord(Tel tel[],int *n);		/*保存到文件函数*/ 
void QuitSystem();						/*退出系统函数*/ 
int main()
{
	Tel tel[MAX_PERSON_NUM]; 		/*定义结构体数组*/ 
	int i,*n,k;
	n=&k;				/*输入初始化人数*/ 
	char m;
	while(1)
	{				
		i=Menu();				/*选择菜单*/ 
		switch(i)
		{
			case 1:
					printf("Now you will input record\n");
					printf("请输入联系人人数:\n");
					scanf("%d",&k);
					InputRecord(tel,n);
					printf("创建通讯录成功!\n");
					break;
			case 2:
					printf("Now display record\n");
					DisplayRecord(tel,n);
					break;
			case 3:
					printf("Are you sure to delete record?(Y/N)\n");
					scanf(" %c",&m);    /*注意：%c前面有一个空格*/
					while(m=='Y'||m=='y')
					{
						DeleteRecord(tel,n);
						printf("删除成功\n");
						printf("Do you want to delete again?(Y/N)\n");
						scanf(" %c",&m);	
					}
					break;	
			case 4:
					printf("Are you sure to search record?(Y/N)\n");
					scanf(" %c",&m);
					while(m=='Y'||m=='y')
					{
						SearchRecord(tel,n);
						printf("Do you want to search again?(Y/N)\n");
						scanf(" %c",&m);	
					}		
					break;
			case 5:
					printf("Are you sure to modify record?(Y/N)\n");
					scanf(" %c",&m);
					while(m=='Y'||m=='y')
					{
						ModifyRecord(tel,n);
						printf("Do you want to search again?(Y/N)\n");
						scanf(" %c",&m);	
					}		
					break;	
			case 6:
					printf("Do you sure to insert record?(Y/N)\n");
					scanf(" %c",&m);
					while(m=='Y'||m=='y')
					{
						InsertRecord(tel,n);
						printf("Do you want to insert again?(Y/N)\n");
						scanf(" %c",&m);	
					}		
					break;
			case 7:
					printf("Are you sure to sort record?(Y/N)\n");
					scanf(" %c",&m);
					while(m=='Y'||m=='y')
					{
						SortRecord(tel,n);
						printf("Do you want to sort again?(Y/N)\n");
						scanf(" %c",&m); 
					}
					break;		
			case 8:
					printf("Now save record to file\n");
					SaveRecord(tel,n);
					printf("保存成功\n");
					break;
			case 0:
					QuitSystem();
					break;				
		}	
	}
	return 0;
}
int Menu()
{
	int i;
	printf("          The telephone-book Management System    \n");
	printf("* 1 input  record				2 display record *\n");
	printf("* 3 delete record	  			4 search  record *\n");
	printf("* 5 modify record				6 insert  record *\n");
	printf("* 7 sort   record				8 save    record *\n");
	printf("* 0 quit   record			 			 *\n");
	printf("******************************************************************\n");
	printf("\n");
	printf("			Please Enter your choice(0~8):		  \n");
	scanf("%d",&i);
	system("cls");
	return i;	
}
void InputRecord(Tel tel[],int *n)		/*初始化联系人，并输出显示*/ 
{
	int i;
	for(i=0;i<*n;i++)
	{
		printf("请输入第%d个联系人信息：\n",i+1);
		printf("请输入编号：\n");
		scanf("%d",&tel[i].no);
		printf("请输入姓名：\n");
		scanf("%s",tel[i].name);
		printf("请输入电话号码：\n");
		scanf("%s",tel[i].phone);
		printf("请输入QQ：\n");
		scanf("%s",tel[i].qq); 
	} 	
	printf("编号\t姓名\t\t电话号码\t\tQQ\t\t\n");
	for(i=0;i<*n;i++)
	{
		printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[i].no,tel[i].name,tel[i].phone,tel[i].qq);
	}
}
void DisplayRecord(Tel tel[],int *n)		/*将联系人信息显示在屏幕上*/ 
{
	int i;
	printf("编号\t姓名\t\t电话号码\t\tQQ\t\t\n");
	for(i=0;i<*n;i++)
	{
		printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[i].no,tel[i].name,tel[i].phone,tel[i].qq);
	}
}
void DeleteRecord(Tel tel[],int *n)			/*按编号，姓名，电话号码，QQ删除联系人*/ 
{
	int i,j,dno,flag=0;
	char dname[15],dphone[15],dqq[15]; 
	printf("1按编号删除\n2按姓名删除\n3按电话号码删除\n4按QQ删除\n请选择删除方式：");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
				printf("请输入编号:\n");
				scanf("%d",&dno);
				for(j=0;j<*n;j++)
				{
					if(dno==tel[j].no)
					{
						tel[j].no=tel[j+1].no;
						strcpy(tel[j].name,tel[j+1].name);
						strcpy(tel[j].phone,tel[j+1].phone);
						strcpy(tel[j].qq,tel[j+1].qq);
						(*n)--;
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("输入有误!\n");
				}
				break;
		case 2:
				printf("请输入姓名:\n");
				scanf("%s",dname);
				for(j=0;j<*n;j++)
				{
					if(stricmp(dname,tel[j].name)==0)
					{
						tel[j].no=tel[j+1].no;
						strcpy(tel[j].name,tel[j+1].name);
						strcpy(tel[j].phone,tel[j+1].phone);
						strcpy(tel[j].qq,tel[j+1].qq);
						(*n)--;
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;	
		case 3:
				printf("请输入电话号码:\n");
				scanf("%s",dphone);		
				for(j=0;j<*n;j++)
				{
					if(stricmp(dphone,tel[j].phone)==0)
					{
						tel[j].no=tel[j+1].no;
						strcpy(tel[j].name,tel[j+1].name);
						strcpy(tel[j].phone,tel[j+1].phone);
						strcpy(tel[j].qq,tel[j+1].qq);
						(*n)--;
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;	
		case 4:
				printf("请输入QQ：\n");
				scanf("%s",dqq);
				for(j=0;j<*n;j++)
				{
					if(stricmp(dqq,tel[j].qq)==0)
					{
						tel[j].no=tel[j+1].no;
						strcpy(tel[j].name,tel[j+1].name);
						strcpy(tel[j].phone,tel[j+1].phone);
						strcpy(tel[j].qq,tel[j+1].qq);
						(*n)--;
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;		
	} 
}
void SearchRecord(Tel tel[],int *n)		/*按编号，姓名，电话号码，QQ查询联系人*/ 
{
	int i,j,sno,flag=0;
	char sname[15],sphone[15],sqq[15];
	printf("1按编号查找\n2按姓名查找\n3按电话号码查找\n4按QQ查找\n请选择查找途径:\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
				printf("请输入编号:\n");
				scanf("%d",&sno);
				for(j=0;j<*n;j++)
				{
					if(sno==tel[j].no)
					{
						printf("找到该联系人，其信息如下:\n");
						printf("编号\t姓名\t\t电话号码\t\tQQ\t\t\n");
						printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
						flag=1;
					}

				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;
		case 2:
				printf("请输入姓名:\n");
				scanf("%s",sname);
				for(j=0;j<*n;j++)
				{
					if(stricmp(sname,tel[j].name)==0)
					{
						printf("找到该联系人，其信息如下:\n");
						printf("编号\t姓名\t\t电话号码\t\tQQ\t\t\n");
						printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;
		case 3:
				printf("请输入电话号码:\n");			
				scanf("%s",sphone);
				for(j=0;j<*n;j++)
				{
					if(stricmp(sphone,tel[j].phone)==0)
					{
						printf("找到该联系人，其信息如下:\n");
						printf("编号\t姓名\t\t电话号码\t\tQQ\t\t\n");
						printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;
		case 4:
				printf("请输入QQ:\n");			
				scanf("%s",sqq);
				for(j=0;j<*n;j++)
				{
					if(stricmp(sqq,tel[j].qq)==0)
					{
						printf("找到该联系人，其信息如下:\n");
						printf("编号\t姓名\t\t电话号码\t\tQQ\t\t\n");
						printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;
	}	
}
void ModifyRecord(Tel tel[],int *n)		/*按编号，姓名，电话号码，QQ修改联系人*/ 
{
	int i,j,mno,flag=0;
	char mname[15],mphone[15],mqq[15];
	printf("1按编号修改\n2按姓名修改\n3按电话号码修改\n4按QQ修改\n请选择修改途径:\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
				printf("请输入编号:\n");
				scanf("%d",&mno);
				for(j=0;j<*n;j++)
				{
					if(mno==tel[j].no)
					{
						ModifyInputRecord(tel,j);
						flag=1;
					}

				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;
		case 2:
				printf("请输入姓名:\n");
				scanf("%s",mname);
				for(j=0;j<*n;j++)
				{
					if(stricmp(mname,tel[j].name)==0)
					{
						ModifyInputRecord(tel,j);
						flag=1;
					}

				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;
		case 3:
				printf("请输入电话号码:\n");			
				scanf("%s",mphone);
				for(j=0;j<*n;j++)
				{
					if(stricmp(mphone,tel[j].phone)==0)
					{
						ModifyInputRecord(tel,j);
						flag=1;
					}

				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;
		case 4:
				printf("请输入QQ:\n");			
				scanf("%s",mqq);
				for(j=0;j<*n;j++)
				{
					if(stricmp(mqq,tel[j].qq)==0)
					{
						ModifyInputRecord(tel,j);
						flag=1;
					}

				}
				if(flag==0)
				{
					printf("输入有误！\n");
				}
				break;
	}	
}
void ModifyInputRecord(Tel tel[],int j)		/*将修改后的联系人信息输出显示*/ 
{	
	int no;
	char name[15],phone[15],qq[15];		
	printf("找到该联系人，其信息如下:\n");
	printf("编号\t姓名\t\t电话号码\t\tQQ\t\t\n");
	printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
	printf("请输入编号：\n");
	scanf("%d",&no);
	printf("请输入姓名：\n");
	scanf("%s",name);
	printf("请输入电话号码：\n");
	scanf("%s",phone);
	printf("请输入QQ：\n");
	scanf("%s",qq); 
	tel[j].no=no;strcpy(tel[j].name,name);strcpy(tel[j].phone,phone);strcpy(tel[j].qq,qq);
	printf("修改后的信息:\n");
	printf("编号\t姓名\t\t电话号码\t\tQQ\t\t\n");
	printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
}
void InsertRecord(Tel tel[],int *n)			/*插入联系人信息*/ 
{
	int no;
	char name[15],phone[15],qq[15];
	printf("请输入编号:\n");
	scanf("%d",&no);
	printf("请输入姓名：\n");
	scanf("%s",name);
	printf("请输入电话号码：\n");
	scanf("%s",phone);
	printf("请输入QQ：\n");
	scanf("%s",qq); 
	tel[*n].no=no;strcpy(tel[*n].name,name);strcpy(tel[*n].phone,phone);strcpy(tel[*n].qq,qq);
	printf("插入的信息：\n");
	printf("编号\t姓名\t\t电话号码\t\tQQ\t\t\n");
	printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[*n].no,tel[*n].name,tel[*n].phone,tel[*n].qq); 
	(*n)++;
}
void SortRecord(Tel tel[],int *n)		/*按编号，姓名升序排序联系人信息*/ 
{
	int i,j,k,min,temp;
	char tempn[15],tempp[15],tempq[15];
	printf("1按编号排序\n2按姓名排序\n请选择排序方式:\n");
	scanf("%d",&i);
	if(i==1)
	{	
		for(j=0;j<*n-1;j++)
		{
			min=j;
			for(k=j+1;k<*n;k++)
			{
				if(tel[min].no>tel[k].no)
				min=k;
			}
			if(min!=j)
			{
				temp=tel[j].no;strcpy(tempn,tel[j].name);strcpy(tempp,tel[j].phone);strcpy(tempq,tel[j].qq);
				tel[j].no=tel[min].no;strcpy(tel[j].name,tel[min].name);strcpy(tel[j].phone,tel[min].phone);strcpy(tel[j].qq,tel[min].qq);
				tel[min].no=temp;strcpy(tel[min].name,tempn);strcpy(tel[min].phone,tempn);strcpy(tel[min].qq,tempq);
			}
		}
	}
	else if(i==2)
	{
		for(j=0;j<*n-1;j++)
		{
			min=j;
			for(k=j+1;k<*n;k++)
			{
				if(stricmp(tel[min].name,tel[k].name)>0)
				min=k;
			}
			if(min!=j)
			{
				temp=tel[j].no;strcpy(tempn,tel[j].name);strcpy(tempp,tel[j].phone);strcpy(tempq,tel[j].qq);
				tel[j].no=tel[min].no;strcpy(tel[j].name,tel[min].name);strcpy(tel[j].phone,tel[min].phone);strcpy(tel[j].qq,tel[min].qq);
				tel[min].no=temp;strcpy(tel[min].name,tempn);strcpy(tel[min].phone,tempn);strcpy(tel[min].qq,tempq);
			}
		}
	}

	else
	{
		printf("请重新输入\n");
	}
	printf("成功进行排序\n");
}
void SaveRecord(Tel tel[],int *n)		/*将联系人信息保存到文件中*/ 
{
	int i;
	FILE *fp;
	fp=fopen("tel.txt","w+");
	if(fp==NULL)
	{
		printf("Fail to open tel.txt\n");
		return;
	}
	fprintf(fp,"编号\t姓名\t\t电话号码\t\t\tQQ\t\t\n");
	for(i=0;i<*n;i++)
	{
		fprintf(fp,"%d\t%s\t\t%s\t\t%s\t\t\n",tel[i].no,tel[i].name,tel[i].phone,tel[i].qq);
	} 
	fclose(fp);
}
void QuitSystem()			/*结束程序*/ 
{
	printf("Quit system,thanks for your using \n");
	exit(0);
}
