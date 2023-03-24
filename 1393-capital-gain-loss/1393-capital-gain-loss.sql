# Write your MySQL query statement below
#man this is one hell of a query , learnt many things from this problem
SELECT stock_name, SUM(
    CASE
        WHEN operation = 'Buy' THEN -price
        ELSE price
    END
) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name