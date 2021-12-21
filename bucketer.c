#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  int i;
  for(i=0;i<nBatteries;i++)
  {
    if(cycles[i]<150)  //if charged<150 then lowCunt
      counts.lowCount++;
    else if((150<=ycles[i]) && (cycles[i]<649))  //if  < charged < 649 then mediumCount
      counts.mediumCount++;
    else if(cycles[i] >=650)
      counts.highCount++;   //if charged >650 then highCount
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100,150, 300,500,600,650,900,1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 2;
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 3;
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
