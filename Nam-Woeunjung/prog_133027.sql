-- 코드를 입력하세요
SELECT B.FLAVOR FROM FIRST_HALF A
JOIN JULY B ON A.FLAVOR = B.FLAVOR
GROUP BY B.FLAVOR
ORDER BY  A.TOTAL_ORDER + SUM(B.TOTAL_ORDER) DESC
LIMIT 3;