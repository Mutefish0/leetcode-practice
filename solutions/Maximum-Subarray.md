#基本思路
该解法只需遍历一次即可完成，思路如下：
对于一个数组A[0...j],若已知其最大子数组为A[0...m]，m<=j
则数组A[0...j+1]的最大子数组有以下情况

* A[0...j+1]的最大子数组就是A[0...j]的最大子数组A[0...m]
* A[0...j+1]的最大子数组为A[n...j+1]，其中n具有如下性质
  * m<=n<=j+1
  * 对数组A求和得到B数组，即B[i]=B[i-1]+A[i]，则有B[m]=min(B[m...j+1])，遍历时只需简单判断，即可保存或更新m
