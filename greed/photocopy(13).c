#include <stdio.h>

typedef struct job{
	float weight;
	float duration_time;
	float final_time;
}JOB;

void print_jobs(JOB *jobs, int jobs_size){
	for(int i = 0; i < jobs_size; i++){
		printf("weight: %.4f, duration_time: %.4f\n", jobs[i].weight, jobs[i].duration_time);
	}
	puts("");
}

//sort the jobs by greater weight with insertion sort algorithm
void sort(JOB *jobs, int jobs_size){
	for(int i = 1; i < jobs_size; i++){
		for(int j = i; j > 0; j--){
			if(jobs[j].weight > jobs[j - 1].weight){
				JOB aux_job = jobs[j];
				jobs[j] = jobs[j-1];
				jobs[j-1] = aux_job;
			}
		}
	}
}

//
float calculate_sum(JOB *jobs, int jobs_size){
	float sum = 0; //the sum of (job weight * job final time) for all jobs

	//add the first job in the sum
	jobs[0].final_time = jobs[0].duration_time; //the first job has final time = duration time
	sum += jobs[0].weight * jobs[0].final_time;

	//add others jobs
	for(int i = 1; i < jobs_size; i++){
		jobs[i].final_time = jobs[i].duration_time + jobs[i - 1].final_time;
		sum += jobs[i].weight * jobs[i].final_time;
	}

	return sum;
}

//receive jobs data from user
void receive_jobs(JOB *jobs, int jobs_size){
	for(int i = 0; i < jobs_size; i++){
		printf("Enter the data for job number %d\n", i);

		printf("Weight: ");
		scanf("%f", &jobs[i].weight);

		printf("Duration time: ");
		scanf("%f", &jobs[i].duration_time);
		puts("");

		jobs[i].final_time = 0;
	}
}

int main(){
	//receive the number of jobs
	printf("How many jobs do you have? ");
	int number_of_jobs = 0;
	scanf("%d", &number_of_jobs);
	puts("");

	//receive jobs
	JOB jobs[number_of_jobs];
	receive_jobs(jobs, number_of_jobs);
	puts("Jobs:");
	print_jobs(jobs, number_of_jobs);

	//sort jobs
	sort(jobs, 2);
	puts("Scheduled jobs:");
	print_jobs(jobs, number_of_jobs);

	//calculate sum
	float sum = calculate_sum(jobs, number_of_jobs);
	printf("Sum: %.4f\n", sum);

	return 0;
}