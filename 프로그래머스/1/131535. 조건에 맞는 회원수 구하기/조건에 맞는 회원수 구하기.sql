-- 코드를 입력하세요
SELECT count(*)
from user_info
where 20 <= age and age <= 29
and year(joined) = 2021