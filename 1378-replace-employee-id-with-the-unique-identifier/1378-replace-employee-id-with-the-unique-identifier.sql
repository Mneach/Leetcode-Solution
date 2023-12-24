/* Write your T-SQL query statement below */


SELECT unique_id, name 
FROM Employees as e
LEFT JOIN EmployeeUni as eu on e.id = eu.id;
