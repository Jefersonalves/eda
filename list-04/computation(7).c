#include <stdio.h>

typedef struct job{
	float super_time;
	float pc_time;
}JOB;

void print_jobs(JOB *jobs, int jobs_size){
	for(int i = 0; i < jobs_size; i++){
		printf("super: %.4f, pc: %.4f\n", jobs[i].super_time, jobs[i].pc_time);
	}
	puts(" ");
}

//sort the jobs by greater posprocess time with insertion sort algorithm
void sort(JOB *jobs, int jobs_size){
	for(int i = 1; i < jobs_size; i++){
		for(int j = i; j > 0; j--){
			if(jobs[j].pc_time > jobs[j - 1].pc_time){
				JOB aux_job = jobs[j];
				jobs[j] = jobs[j-1];
				jobs[j-1] = aux_job;
			}
		}
	}
}

//receive jobs data from user
void receive_jobs(JOB *jobs, int jobs_size){
	for(int i = 0; i < jobs_size; i++){
		printf("Enter the data for job number %d\n", i);

		printf("Super time: ");
		scanf("%f", &jobs[i].super_time);

		printf("Pc time: ");
		scanf("%f", &jobs[i].pc_time);
		puts("");
	}
}

//calculate the total time to process all jobs
float calculate_process_time(JOB *jobs, int jobs_size){
	float total_time = jobs[0].super_time + jobs[0].pc_time; //time to finish the process
	float super_sum = jobs[0].super_time; //sum of super_time for all jobs

	for(int i = 1; i < jobs_size; i++){
		if((jobs[i].pc_time + jobs[i].super_time + super_sum) > (super_sum + jobs[i - 1].pc_time)){
			super_sum += jobs[i].super_time;
			total_time = super_sum + jobs[i].pc_time;
		}else{
			//nothig to do
		}
	}

	return total_time;
}

int main(){
	//receive the number of jobs
	printf("How many jobs do you have? ");
	int number_of_jobs = 0;
	scanf("%d", &number_of_jobs);
	puts("");

	JOB jobs[number_of_jobs];
	receive_jobs(jobs, number_of_jobs);
	puts("Jobs:");
	print_jobs(jobs, number_of_jobs);

	sort(jobs, number_of_jobs);
	puts("Scheduled jobs:");
	print_jobs(jobs, number_of_jobs);

	float total_process_time = calculate_process_time(jobs, number_of_jobs);
	printf("Total pocess time: %.4f\n", total_process_time);

	return 0;
}