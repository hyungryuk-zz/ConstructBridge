#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int testCase;
	scanf("%d", &testCase);
	int n, m;
	while (testCase--) {
		scanf("%d %d", &n, &m);
		int **dp = (int **)malloc(sizeof(int*)*(n + 1));
		for (int i = 0; i <= n; i++) {
			dp[i] = (int *)malloc(sizeof(int)*(m + 1));
			memset(dp[i], 0, sizeof(int)*(m + 1));
		}
		for (int i = 1; i <= m; i++) {
			dp[1][i] = i;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				for (int k = 1; k < j; k++) {
					dp[i][j] += (dp[i - 1][k] - dp[i - 1][k - 1])*(j - k);
				}
			}
		}
		printf("%d\n", dp[n][m]);
		for (int i = 0; i <= n; i++) {
			free(dp[i]);
		}
		free(dp);
	}

}