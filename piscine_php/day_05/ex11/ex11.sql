SELECT UPPER(user_card.last_name) AS "NAME", user_card.first_name, price
FROM user_card
INNER JOIN member, subscription
WHERE member.id_user_card = user_card.id_user
AND subscription.id_sub = member.id_sub
AND subscription.price > 42
ORDER BY last_name ASC, first_name ASC;
