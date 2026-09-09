def coin_change(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0 # Số xu để đổi 0 đồng là 0

    for i in range(1, amount + 1):
        for coin in coins:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[amount] if dp[amount] != float('inf') else -1

he_thong_tien = [1, 3, 4]
so_tien_can_doi = 6
print(f"Số tờ tiền ít nhất: {coin_change(he_thong_tien, so_tien_can_doi)}")


# 1, 4, 8, 36, 49
# 72
# 
#