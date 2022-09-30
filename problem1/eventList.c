#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *evList =malloc(sizeof(EventList));
    evList->head=NULL;
    evList->last=NULL;

    evList->isEmpty=1;
    return evList;
}

void DestroyEventList(EventList *this)
{
    free (this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *evTemp=this->head;
    while(evTemp!=NULL)
    {
        if(strcmp(evTemp->eventName,name)==0)
        {     
        return evTemp;     
        }
        evTemp=evTemp->next;
    
    }

    return evTemp;
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
            Event*evTemp= this->head;
            while(evTemp!=NULL)
            {
                if(strcmp(evTemp->eventName,event->eventName)!=0)
                {
                    if((evTemp==this->last) && (add==0))
                    {
                        this->last->next= event;
                        this->last=event;
                        add=1;
                    }
                    evTemp=evTemp->next;
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
        Event *evTemp = this->head ;
        Event *evSiguiente = evTemp->next;
        if(strcmp(evTemp->eventName,name)!=0)
        {
            while(evSiguiente!=NULL)
            {
                if(strcmp(evSiguiente->eventName,name)==0)
                {
                    evTemp->next=evSiguiente->next;
                    if(evSiguiente->next=NULL)
                    {
                        this->last=evTemp;
                    }
                    free(evSiguiente);
                    return;
                    {
                        evTemp=evSiguiente;
                        evSiguiente=evSiguiente->next;
                    }
                }
            }
        }
        else
        {
            if(evTemp->next==NULL)
            {
                free(evTemp);
                this->head=NULL;
                this->last=NULL;
                this->isEmpty=1;
            }
            else
            {
                free(evTemp);
                this->head=evSiguiente;
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
        Event *evTemp=this->head;
        while(evTemp!=NULL)
        {
            printf("%s\n",evTemp->eventName);
            evTemp=evTemp->next;
        }
    }   
}
