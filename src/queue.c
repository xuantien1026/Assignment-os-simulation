#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size < MAX_QUEUE_SIZE){
		q->proc[q->size] = proc;
		q->size += 1;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose priority is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) return NULL;
	int chosen_proc_index = 0;
	uint32_t max_priority = (q->proc[0])->priority;
	// Get highest priority process
	for (int i = 0; i < q->size; ++i){
		if ((q->proc[i])->priority > max_priority){
			max_priority = (q->proc[i])->priority;
			chosen_proc_index = i;
		}
	}
	struct pcb_t * chosen_pcb = (q->proc[chosen_proc_index]);
	// Remove chosen process from the array and move others up.
	for (int i = chosen_proc_index; i < q->size - 1; ++i)
		q->proc[i] = q->proc[i+1];
	q->size -= 1;

	return chosen_pcb;
}

