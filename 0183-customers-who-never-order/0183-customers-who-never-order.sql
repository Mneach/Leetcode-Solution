/* Write your T-SQL query statement below */

select name as Customers from Customers
where Customers.id NOT IN
(
    select Customers.id  from Customers
    join Orders on Orders.customerId = Customers.id
)