#ifndef FUNCTIONS_H
#define FUNCTIONS_H /*Appointment Diary*/
typedef struct{
    
    float beginT;
    float endT;
    int RoomNum;
	
}Meeting;

typedef struct{
	int capacity;
	int index;
    Meeting** meetings;
}AD;

/* AD meeting */

AD* create_AD(int capacity);
Meeting* create_meeting();
int insert_appointment_into_AD(AD* ad_ptr,Meeting* m_ptr);     /*insertion in sorted order ( by begin hour )*/
int m_remove_appointment_from_AD(AD* ad_ptr,float begin);     /* by begin hour )*/
Meeting* Find(AD* ad_ptr,float begin);         /*by begin hour*/
void print(AD*  ad_ptr);
void destroy(AD*  ad_ptr);

#endif


