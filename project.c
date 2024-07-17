#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct patient{
    int patient_id;
    char name[50];
    int contact;
    char med_record[200];
};
struct appointment{
    int id;
    int patient_id;
    int provider_id;
    char provider_name[50];
    char spcl[50];
    char date[20];
    char time[10];
};
void book_appointments();
void medical_records();
void send_reminders();
void display_appointments();

int main(){
int opt;
while(1){
    printf("HEALTHCARE MANAGEMENT SYSTEM\n");
    printf("1-book an appointment\n");
    printf("2-manage medical records\n");
    printf("3-send appointment reminders\n");
    printf("4-display appointments\n");
    printf("5-exit\n");
    scanf("%d",&opt);
switch(opt){
    case 1:
        book_appointments();
        break;
    case 2:
        medical_records();
        break;
    case 3:
        send_reminders();
        break;
    case 4:
        display_appointments();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("invalid choice\n");
    }
    }
return 0;
}
void book_appointments(){
    struct appointment apt;
    printf("enter appointment ID: ");
    scanf("%d",&apt.id);
    printf("enter patient ID: ");
    scanf("%d",&apt.patient_id);
    printf("enter provider ID: ");
    scanf("%d",&apt.provider_id);
    printf("enter provider name: ");
    scanf("%s",apt.provider_name);
    printf("enter provider specialization: ");
    scanf("%s",apt.spcl);
    printf("enter date: ");
    scanf("%s",apt.date);
    printf("enter time: ");
    scanf("%s",apt.time); 
    FILE*fp=fopen("appointments.txt","a");
    if(fp==NULL){
    printf("error in opeining file\n");
    return;
    }
    fprintf(fp,"%d %d %d %s %s %s %s\n",
        apt.id,apt.patient_id,apt.provider_id,apt.provider_name,apt.spcl,apt.date,apt.time);
    fclose(fp);
    printf("appointment booked successfully...\n");
}
void medical_records(){
   struct patient pt;
    printf("enter patient ID: ");
    scanf("%d",&pt.patient_id);
    printf("enter patient name: ");
    scanf("%s",pt.name);
    printf("enter patient contact number: ");
    scanf("%d",&pt.contact);
    printf("enter medical record of patient: ");
    scanf("%s",pt.med_record);
    FILE*fp=fopen("patients.txt","a");
    if(fp==NULL){
    printf("error in opeining file\n");
    return;
    }
    fprintf(fp,"%d %s %d %s\n",
            pt.patient_id,pt.name,pt.contact,pt.med_record);
    fclose(fp);
    printf("medical record updated successfully...\n");
}
void send_reminders(){
    struct appointment apt;
    FILE*fp=fopen("appointments.txt","r");
    if(fp==NULL){
    printf("error in opeining file\n");
    return;
    }
    printf("appointment reminders...\n");
    while(fscanf(fp,"%d %d %d %s %s %s %s",
        &apt.id,&apt.patient_id,&apt.provider_id,apt.provider_name,apt.spcl,apt.date,apt.time)!=EOF){
        printf("REMINDER-appointment ID %d on %s at %s\n",apt.id,apt.date,apt.time);
    }
    fclose(fp);
}
void display_appointments(){
     struct appointment apt;
    FILE*fp=fopen("appointments.txt","r");
    if(fp==NULL){
    printf("error in opeining file\n");
    return;
    }
    printf("appointments...\n");
    while(fscanf(fp,"%d %d %d %s %s %s %s",&apt.id,&apt.patient_id,&apt.provider_id,apt.provider_name,apt.spcl,apt.date,apt.time)!=EOF){
    printf("appointment ID:%d \npatient ID:%d \nprovider ID:%d \nprovider name:%s \nspecialization:%s \ndate:%s \nTime:%s \n",apt.id,apt.patient_id,apt.provider_id,apt.provider_name,apt.spcl,apt.date,apt.time);
    }
    fclose(fp);
}  
