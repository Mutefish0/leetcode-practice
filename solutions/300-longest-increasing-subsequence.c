int lengthOfLIS(int* nums, int numsSize) {
  if (numsSize < 1) {
    return 0;
  }

  int dp[numsSize];
  int max = 1;

  for (int i = 0; i < numsSize; i++) {
    dp[i] = 1;
  }

  for (int i = 1; i < numsSize; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j] && dp[j] >= dp[i]) {
        dp[i] = dp[j] + 1;
        if (dp[i] > max) {
          max = dp[i];
        }
      }
    }
  }

  return max;
}