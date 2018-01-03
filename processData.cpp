/*
 * ==========================================================================================
 * Name        : processData.cpp
 * Description : student code for Assignment 2 - Data structures and Algorithms - Fall 2017
 * ==========================================================================================
 */
#include <iostream>
#include <vector>
#include <functional>
#include <math.h>
#include "requestLib.h"
#include "dbLib.h"

using namespace std;

#define GPS_DISTANCE_ERROR 0.005


bool initVMGlobalData(void** pGData) {
    // TODO: allocate and initialize global data
    // return false if failed
    return true;
}

void releaseVMGlobalData(void* pGData) {
    // TODO: do your cleanup, left this empty if you don't have any dynamically allocated data

}

bool processRequest(VM_Request &request, L1List<VM_Record> &recordList, void *pGData) {
    // TODO: Your code goes here
    
    string req;
    req = request.code;
    if(request.code[0]=='1' && request.code[1]=='_') {
        cout<<request.code<<": ";
        request_1(req, recordList);
        return true;
    }
    if(request.code[0]=='2' && request.code[1]=='_') {
        cout<<request.code<<": ";
        request_2(req, recordList);
        return true;
    }
    if(request.code[0]=='3' && request.code[1]=='_') {
        cout<<request.code<<": ";
        request_3(req, recordList);
        return true;
    }
    if(request.code[0]=='4' && request.code[1]=='_') {
        cout<<request.code<<": ";
        request_4(req, recordList);
        return true;
    }
    if(request.code[0]=='5' && request.code[1]=='_') {
        cout<<request.code<<": ";
        request_5(req, recordList);
        return true;
    }
    if(request.code[0]=='6' && request.code[1]=='_') {
        cout<<request.code<<": ";
        request_6(req, recordList);
        return true;
    }
    if(request.code[0]=='7' && request.code[1]=='_') {
        cout<<request.code<<": ";
        request_7(req, recordList);
        return true;
    }
    if(request.code[0]=='8' && request.code[1]=='_') {
        cout<<request.code<<": ";
        request_8(req, recordList);
        return true;
    }
    if(request.code[0]=='9' && request.code[1]=='_') {
        cout<<request.code<<": ";
        request_9(req, recordList);
        return true;
    }
    
    // return false for invalid events
    return false;
}

void request_1(string req, L1List<VM_Record> &recordList) {
    int i=2, n=0;
    char ID1[ID_MAX_LENGTH], ID2[ID_MAX_LENGTH];
    while(i<ID_MAX_LENGTH) {
        ID1[n] = req[i];
        if(req[i]=='_') {  ID1[n] = '\0'; n=0; i++; break;  }
        i++; n++;
    }
    while (i<ID_MAX_LENGTH) {
        ID2[n] = req[i];
        if(req[i]=='_') {  ID2[n] = '\0'; n=0; i++; break;  }
        i++; n++;
    }
    //cout<<ID1<<" "<<ID2<<endl;
    int hh, mm, ss;
    char hours[3], min[3], second[3];
    hours[0] = req[i]; i++; hours[1] = req[i]; i++; hours[2] = '\0';
    hh = atoi(hours);
    min[0] = req[i]; i++; min[1] = req[i]; i++; min[2] = '\0';
    mm = atoi(min);
    second[0] = req[i]; i++; second[1] = req[i]; i++; second[2] = '\0';
    ss = atoi(second);
    cout<<endl;
}

void request_2(string req, L1List<VM_Record> &recordList) {
    int i=2, n=0;
    char temp_long[REQUEST_CODE_SIZE];
    while (i<REQUEST_CODE_SIZE) {
        temp_long[n] = req[i];
        if(req[i]=='_') {  temp_long[n] = '\0'; n=0; i++; break;  }
        i++; n++;
    }
    //double longtemp = atof(temp_long);
    string direction;
    direction = req[i];
    cout<<endl;
}

void request_3(string req, L1List<VM_Record> &recordList) {
    int i=2, n=0;
    char temp_lat[REQUEST_CODE_SIZE];
    while (i<REQUEST_CODE_SIZE) {
        temp_lat[n] = req[i];
        if(req[i]=='_') {  temp_lat[n] = '\0'; n=0; i++; break;  }
        i++; n++;
    }
    //double lat_temp = atof(temp_lat);
    string direction;
    direction = req[i];
    cout<<endl;
}

void request_4(string req, L1List<VM_Record> &recordList) {
    int i=2, n=0;
    char temp_long[REQUEST_CODE_SIZE], temp_lat[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        temp_long[n] = req[i];
        if(req[i]=='_') { temp_long[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    while(i<REQUEST_CODE_SIZE) {
        temp_lat[n] = req[i];
        if(req[i]== '_' ) { temp_lat[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double Along = atof(temp_long), Alat = atof(temp_lat);
    char ban_kinh[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        ban_kinh[n] = req[i];
        if(req[i]=='_') { ban_kinh[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double r = atof(ban_kinh);
    char h1[3], h2[3];
    h1[0] = req[i]; i++; h1[1] = req[i]; i++; h1[2] = '\0'; i++;
    h2[0] = req[i]; i++; h2[1] = req[i]; i++; h2[2] = '\0'; i++;
    int hour_begin = atoi(h1), hour_end = atoi(h2);
    //cout<<Along<<" "<<Alat<<" "<<r<<" "<<hour_begin<<" "<<hour_end<<endl;
    cout<<endl;
}

void request_5(string req, L1List<VM_Record> &recordList) {
    int i=2, n=0;
    char so_hieu[ID_MAX_LENGTH];
    while(i<ID_MAX_LENGTH) {
        so_hieu[n] = req[i];
        if(req[i]=='_') {  so_hieu[n] = '\0'; n=0; i++; break;  }
        i++; n++;
    }
    char temp_long[REQUEST_CODE_SIZE], temp_lat[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        temp_long[n] = req[i];
        if(req[i]=='_') { temp_long[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    while(i<REQUEST_CODE_SIZE) {
        temp_lat[n] = req[i];
        if(req[i]== '_' ) { temp_lat[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double Along = atof(temp_long), Alat = atof(temp_lat);
    char ban_kinh[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        ban_kinh[n] = req[i];
        if(req[i]=='_') { ban_kinh[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double r = atof(ban_kinh);
    cout<<endl;
}

void request_6(string req, L1List<VM_Record> &recordList) {
    int i=2, n=0;
    char temp_long[REQUEST_CODE_SIZE], temp_lat[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        temp_long[n] = req[i];
        if(req[i]=='_') { temp_long[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    while(i<REQUEST_CODE_SIZE) {
        temp_lat[n] = req[i];
        if(req[i]== '_' ) { temp_lat[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double Along = atof(temp_long), Alat = atof(temp_lat);
    char soluong[12];
    while(i<REQUEST_CODE_SIZE) {
        soluong[n] = req[i];
        if(req[i]== '_' ) { temp_lat[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    int num = atoi(soluong);
    int hh, mm;
    char hours[3], min[3];
    hours[0] = req[i]; i++; hours[1] = req[i]; i++; hours[2] = '\0';
    hh = atoi(hours);
    min[0] = req[i]; i++; min[1] = req[i]; i++; min[2] = '\0';
    mm = atoi(min);
    cout<<endl;
}

void request_7(string req, L1List<VM_Record> &recordList) {
    int i=2, n=0;
    char temp_long[REQUEST_CODE_SIZE], temp_lat[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        temp_long[n] = req[i];
        if(req[i]=='_') { temp_long[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    while(i<REQUEST_CODE_SIZE) {
        temp_lat[n] = req[i];
        if(req[i]== '_' ) { temp_lat[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double Along = atof(temp_long), Alat = atof(temp_lat);
    char soluong[12];
    while(i<REQUEST_CODE_SIZE) {
        soluong[n] = req[i];
        if(req[i]== '_' ) { temp_lat[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    int num = atoi(soluong);
    char ban_kinh[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        ban_kinh[n] = req[i];
        if(req[i]=='_') { ban_kinh[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double r = atof(ban_kinh);
    int hh, mm;
    char hours[3], min[3];
    hours[0] = req[i]; i++; hours[1] = req[i]; i++; hours[2] = '\0';
    hh = atoi(hours);
    min[0] = req[i]; i++; min[1] = req[i]; i++; min[2] = '\0';
    mm = atoi(min);
    //cout<<Along<<" "<<Alat<<" "<<num<<" "<<r<<" "<<hh<<" "<<mm;
    cout<<endl;
}

void request_8(string req, L1List<VM_Record> &recordList) {
    int i=2, n=0;
    char temp_long[REQUEST_CODE_SIZE], temp_lat[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        temp_long[n] = req[i];
        if(req[i]=='_') { temp_long[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    while(i<REQUEST_CODE_SIZE) {
        temp_lat[n] = req[i];
        if(req[i]== '_' ) { temp_lat[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double Along = atof(temp_long), Alat = atof(temp_lat);
    char ban_kinh[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        ban_kinh[n] = req[i];
        if(req[i]=='_') { ban_kinh[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double r = atof(ban_kinh);
    int hh, mm;
    char hours[3], min[3];
    hours[0] = req[i]; i++; hours[1] = req[i]; i++; hours[2] = '\0';
    hh = atoi(hours);
    min[0] = req[i]; i++; min[1] = req[i]; i++; min[2] = '\0';
    mm = atoi(min);
    //cout<<Along<<" "<<Alat<<" "<<r<<" "<<hh<<" "<<mm;
    cout<<endl;
}

void request_9(string req, L1List<VM_Record> &recordList) {
    int i=2, n=0;
    char temp_long[REQUEST_CODE_SIZE], temp_lat[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        temp_long[n] = req[i];
        if(req[i]=='_') { temp_long[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    while(i<REQUEST_CODE_SIZE) {
        temp_lat[n] = req[i];
        if(req[i]== '_' ) { temp_lat[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double Along = atof(temp_long), Alat = atof(temp_lat);
    char ban_kinh[REQUEST_CODE_SIZE];
    while(i<REQUEST_CODE_SIZE) {
        ban_kinh[n] = req[i];
        if(req[i]=='_') { ban_kinh[n] = '\0'; n=0; i++; break; }
        i++; n++;
    }
    double r = atof(ban_kinh);
    int hh, mm;
    char hours[3], min[3];
    hours[0] = req[i]; i++; hours[1] = req[i]; i++; hours[2] = '\0';
    hh = atoi(hours);
    min[0] = req[i]; i++; min[1] = req[i]; i++; min[2] = '\0';
    mm = atoi(min);
    //cout<<Along<<" "<<Alat<<" "<<r<<" "<<hh<<" "<<mm;
    cout<<endl;
}
