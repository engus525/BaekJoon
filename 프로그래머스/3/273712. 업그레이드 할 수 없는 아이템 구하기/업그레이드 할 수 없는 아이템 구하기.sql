-- 코드를 작성해주세요
select II.item_id, II.item_name, II.rarity
from item_info II
join item_tree IT on II.item_id = IT.item_id
where II.item_id not in
(
    select parent_item_id
    from item_tree
    where parent_item_id is not null
)
order by II.item_id desc