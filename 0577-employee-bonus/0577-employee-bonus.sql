/* Write your T-SQL query statement below */




Select name, bonus from employee
LEFT JOIN Bonus on employee.empId = bonus.empId
where bonus < 1000 OR bonus is null

