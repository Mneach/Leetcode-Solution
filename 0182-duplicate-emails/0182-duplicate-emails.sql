/* Write your T-SQL query statement below */

SELECT Email 
FROM PERSON
GROUP BY Email
HAVING count(Email) > 1