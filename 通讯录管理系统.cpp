#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<conio.h>
#include<windows.h>
#define MAX_PERSON_NUM 30  /*�����������*/ 
 
typedef struct address		/*������ϵ�������Ϣ*/ 
{
	int no;
	char name[15];
	char phone[15];
	char qq[15];
}Tel;
int Menu();					/*ѡ��˵�*/ 						/* *n ��ַ ��ϵ�˸��������ڸ�����������*/ 
void InputRecord(Tel tel[],int *n); 	/*��ʼ�����뺯��*/ 
void DisplayRecord(Tel tel[],int *n);	/*��ʾ����*/ 	
void DeleteRecord(Tel tel[],int *n);	/*ɾ������*/ 
void SearchRecord(Tel tel[],int *n);	/*��ѯ����*/ 
void ModifyRecord(Tel tel[],int *n);	/*�޸ĺ���*/ 
void ModifyInputRecord(Tel tel[],int j);	/*�޸ĺ���Ϣ�������*/ 
void InsertRecord(Tel tel[],int *n);	/*���뺯��*/ 
void SortRecord(Tel tel[],int *n);		/*������*/ 
void SaveRecord(Tel tel[],int *n);		/*���浽�ļ�����*/ 
void QuitSystem();						/*�˳�ϵͳ����*/ 
int main()
{
	Tel tel[MAX_PERSON_NUM]; 		/*����ṹ������*/ 
	int i,*n,k;
	n=&k;				/*�����ʼ������*/ 
	char m;
	while(1)
	{				
		i=Menu();				/*ѡ��˵�*/ 
		switch(i)
		{
			case 1:
					printf("Now you will input record\n");
					printf("��������ϵ������:\n");
					scanf("%d",&k);
					InputRecord(tel,n);
					printf("����ͨѶ¼�ɹ�!\n");
					break;
			case 2:
					printf("Now display record\n");
					DisplayRecord(tel,n);
					break;
			case 3:
					printf("Are you sure to delete record?(Y/N)\n");
					scanf(" %c",&m);    /*ע�⣺%cǰ����һ���ո�*/
					while(m=='Y'||m=='y')
					{
						DeleteRecord(tel,n);
						printf("ɾ���ɹ�\n");
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
					printf("����ɹ�\n");
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
void InputRecord(Tel tel[],int *n)		/*��ʼ����ϵ�ˣ��������ʾ*/ 
{
	int i;
	for(i=0;i<*n;i++)
	{
		printf("�������%d����ϵ����Ϣ��\n",i+1);
		printf("�������ţ�\n");
		scanf("%d",&tel[i].no);
		printf("������������\n");
		scanf("%s",tel[i].name);
		printf("������绰���룺\n");
		scanf("%s",tel[i].phone);
		printf("������QQ��\n");
		scanf("%s",tel[i].qq); 
	} 	
	printf("���\t����\t\t�绰����\t\tQQ\t\t\n");
	for(i=0;i<*n;i++)
	{
		printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[i].no,tel[i].name,tel[i].phone,tel[i].qq);
	}
}
void DisplayRecord(Tel tel[],int *n)		/*����ϵ����Ϣ��ʾ����Ļ��*/ 
{
	int i;
	printf("���\t����\t\t�绰����\t\tQQ\t\t\n");
	for(i=0;i<*n;i++)
	{
		printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[i].no,tel[i].name,tel[i].phone,tel[i].qq);
	}
}
void DeleteRecord(Tel tel[],int *n)			/*����ţ��������绰���룬QQɾ����ϵ��*/ 
{
	int i,j,dno,flag=0;
	char dname[15],dphone[15],dqq[15]; 
	printf("1�����ɾ��\n2������ɾ��\n3���绰����ɾ��\n4��QQɾ��\n��ѡ��ɾ����ʽ��");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
				printf("��������:\n");
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
					printf("��������!\n");
				}
				break;
		case 2:
				printf("����������:\n");
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
					printf("��������\n");
				}
				break;	
		case 3:
				printf("������绰����:\n");
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
					printf("��������\n");
				}
				break;	
		case 4:
				printf("������QQ��\n");
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
					printf("��������\n");
				}
				break;		
	} 
}
void SearchRecord(Tel tel[],int *n)		/*����ţ��������绰���룬QQ��ѯ��ϵ��*/ 
{
	int i,j,sno,flag=0;
	char sname[15],sphone[15],sqq[15];
	printf("1����Ų���\n2����������\n3���绰�������\n4��QQ����\n��ѡ�����;��:\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
				printf("��������:\n");
				scanf("%d",&sno);
				for(j=0;j<*n;j++)
				{
					if(sno==tel[j].no)
					{
						printf("�ҵ�����ϵ�ˣ�����Ϣ����:\n");
						printf("���\t����\t\t�绰����\t\tQQ\t\t\n");
						printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
						flag=1;
					}

				}
				if(flag==0)
				{
					printf("��������\n");
				}
				break;
		case 2:
				printf("����������:\n");
				scanf("%s",sname);
				for(j=0;j<*n;j++)
				{
					if(stricmp(sname,tel[j].name)==0)
					{
						printf("�ҵ�����ϵ�ˣ�����Ϣ����:\n");
						printf("���\t����\t\t�绰����\t\tQQ\t\t\n");
						printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("��������\n");
				}
				break;
		case 3:
				printf("������绰����:\n");			
				scanf("%s",sphone);
				for(j=0;j<*n;j++)
				{
					if(stricmp(sphone,tel[j].phone)==0)
					{
						printf("�ҵ�����ϵ�ˣ�����Ϣ����:\n");
						printf("���\t����\t\t�绰����\t\tQQ\t\t\n");
						printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("��������\n");
				}
				break;
		case 4:
				printf("������QQ:\n");			
				scanf("%s",sqq);
				for(j=0;j<*n;j++)
				{
					if(stricmp(sqq,tel[j].qq)==0)
					{
						printf("�ҵ�����ϵ�ˣ�����Ϣ����:\n");
						printf("���\t����\t\t�绰����\t\tQQ\t\t\n");
						printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
						flag=1;
					}
				}
				if(flag==0)
				{
					printf("��������\n");
				}
				break;
	}	
}
void ModifyRecord(Tel tel[],int *n)		/*����ţ��������绰���룬QQ�޸���ϵ��*/ 
{
	int i,j,mno,flag=0;
	char mname[15],mphone[15],mqq[15];
	printf("1������޸�\n2�������޸�\n3���绰�����޸�\n4��QQ�޸�\n��ѡ���޸�;��:\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
				printf("��������:\n");
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
					printf("��������\n");
				}
				break;
		case 2:
				printf("����������:\n");
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
					printf("��������\n");
				}
				break;
		case 3:
				printf("������绰����:\n");			
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
					printf("��������\n");
				}
				break;
		case 4:
				printf("������QQ:\n");			
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
					printf("��������\n");
				}
				break;
	}	
}
void ModifyInputRecord(Tel tel[],int j)		/*���޸ĺ����ϵ����Ϣ�����ʾ*/ 
{	
	int no;
	char name[15],phone[15],qq[15];		
	printf("�ҵ�����ϵ�ˣ�����Ϣ����:\n");
	printf("���\t����\t\t�绰����\t\tQQ\t\t\n");
	printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
	printf("�������ţ�\n");
	scanf("%d",&no);
	printf("������������\n");
	scanf("%s",name);
	printf("������绰���룺\n");
	scanf("%s",phone);
	printf("������QQ��\n");
	scanf("%s",qq); 
	tel[j].no=no;strcpy(tel[j].name,name);strcpy(tel[j].phone,phone);strcpy(tel[j].qq,qq);
	printf("�޸ĺ����Ϣ:\n");
	printf("���\t����\t\t�绰����\t\tQQ\t\t\n");
	printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[j].no,tel[j].name,tel[j].phone,tel[j].qq);
}
void InsertRecord(Tel tel[],int *n)			/*������ϵ����Ϣ*/ 
{
	int no;
	char name[15],phone[15],qq[15];
	printf("��������:\n");
	scanf("%d",&no);
	printf("������������\n");
	scanf("%s",name);
	printf("������绰���룺\n");
	scanf("%s",phone);
	printf("������QQ��\n");
	scanf("%s",qq); 
	tel[*n].no=no;strcpy(tel[*n].name,name);strcpy(tel[*n].phone,phone);strcpy(tel[*n].qq,qq);
	printf("�������Ϣ��\n");
	printf("���\t����\t\t�绰����\t\tQQ\t\t\n");
	printf("%d\t%s\t\t%s\t\t%s\t\t\n",tel[*n].no,tel[*n].name,tel[*n].phone,tel[*n].qq); 
	(*n)++;
}
void SortRecord(Tel tel[],int *n)		/*����ţ���������������ϵ����Ϣ*/ 
{
	int i,j,k,min,temp;
	char tempn[15],tempp[15],tempq[15];
	printf("1���������\n2����������\n��ѡ������ʽ:\n");
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
		printf("����������\n");
	}
	printf("�ɹ���������\n");
}
void SaveRecord(Tel tel[],int *n)		/*����ϵ����Ϣ���浽�ļ���*/ 
{
	int i;
	FILE *fp;
	fp=fopen("tel.txt","w+");
	if(fp==NULL)
	{
		printf("Fail to open tel.txt\n");
		return;
	}
	fprintf(fp,"���\t����\t\t�绰����\t\t\tQQ\t\t\n");
	for(i=0;i<*n;i++)
	{
		fprintf(fp,"%d\t%s\t\t%s\t\t%s\t\t\n",tel[i].no,tel[i].name,tel[i].phone,tel[i].qq);
	} 
	fclose(fp);
}
void QuitSystem()			/*��������*/ 
{
	printf("Quit system,thanks for your using \n");
	exit(0);
}
