#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */

	q->proc[q->size++] = proc;

}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */

	if (!empty(q)){
	    struct pcb_t *temp = q->proc[0];
		int idx = 0;
	    for (int i = 1; i < q->size; i++){
	        if (temp->priority < q->proc[i]->priority) {
	        	temp = q->proc[i];
	        	idx = i;
	        }
	    }
	    idx++;
	    while (idx < q->size){
	    	q->proc[idx - 1] = q->proc[idx];
	    	idx++;
	    }
	    q->size--;
	    q->proc[q->size] = NULL;
	    return temp;
	}

	return NULL;
}

