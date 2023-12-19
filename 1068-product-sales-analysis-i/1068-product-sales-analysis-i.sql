/* Write your T-SQL query statement below */

select product_name, year, price 
FROM Product 
JOIN Sales on Product.product_id = Sales.product_id