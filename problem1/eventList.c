#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{

    EventList *eventList =malloc(sizeof(EventList));
    eventList->head=NULL;
    eventList->last=NULL;

    eventList->isEmpty=1;
    return eventList;
}

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
Event *eventoTemp=this->head;
while(eventoTemp!=NULL)
    {
        if(strcmp(eventoTemp->eventName,name)==0)
        {
            return eventoTemp;     
        }
        eventoTemp=eventoTemp->next;
    
    }
    return eventoTemp;
}

void AddEvent(EventList *this, Event *event)
{
   
    if(event->eventName!=NULL)
    {
        if((this->head==NULL) && (this->isEmpty==1))
        {
            this->head = event;
            this->last = event;
            this->isEmpty=0;
        }
        else
        {
            int add=0;
            Event *eventoTemp= this->head;
            while(eventoTemp!=NULL)
            {      
                if(strcmp(eventoTemp->eventName,event->eventName)!=0)
                {
                    if((eventoTemp==this->last) && (add==0))
                    {
                        this->last->next= event;
                        this->last=event;
                        add=1;
                    }
                    eventoTemp=eventoTemp->next;       
                }
                else
                {
                    return;
                }
            }  
        }
    }
}

void RemoveEvent(EventList *this, char *name)
{
    if(this->isEmpty==0)
    {
        Event *eventoTemp = this->head ;
        Event *eventosig = eventoTemp->next;
        if(strcmp(eventoTemp->eventName,name)!=0)
        {
            while(eventosig!=NULL)
            {
                if(strcmp(eventosig->eventName,name)==0)
                {
                    eventoTemp->next=eventosig->next;
                    if(eventosig->next=NULL)
                    {
                        this->last=eventoTemp; 
                    }
                    DestroyEvent(eventosig);
                    return;
                }  
            eventoTemp=eventosig;
            eventosig=eventosig->next;
            }
         
        }
        else 
        {
            if(eventoTemp->next==NULL)
            {
                DestroyEvent(eventoTemp);
                this->head=NULL;
                this->last=NULL; 
                this->isEmpty=1;
            }
            else
            {
                DestroyEvent(eventoTemp);
                this->head=eventosig;
            }
        }
    }
}

void ListEvents(EventList *this)
{
    if(this->isEmpty==1)
    {
        printf("empty\n");
    }
    else
    {
        Event *eventoTemp=this->head;
        while(eventoTemp!=NULL)
        {
        printf("%s\n",eventoTemp->eventName);
        eventoTemp=eventoTemp->next;
        }   
    }
}