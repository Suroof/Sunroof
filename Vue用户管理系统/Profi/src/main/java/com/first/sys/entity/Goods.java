package com.first.sys.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import java.io.Serializable;
import java.math.BigDecimal;

/**
 * <p>
 * 
 * </p>
 *
 * @author baomidou
 * @since 2024-09-12
 */
public class Goods implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    private String product;

    private BigDecimal todayCost;

    private BigDecimal monthCost;

    private BigDecimal totalCost;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }
    public String getProduct() {
        return product;
    }

    public void setProduct(String product) {
        this.product = product;
    }
    public BigDecimal getTodayCost() {
        return todayCost;
    }

    public void setTodayCost(BigDecimal todayCost) {
        this.todayCost = todayCost;
    }
    public BigDecimal getMonthCost() {
        return monthCost;
    }

    public void setMonthCost(BigDecimal monthCost) {
        this.monthCost = monthCost;
    }
    public BigDecimal getTotalCost() {
        return totalCost;
    }

    public void setTotalCost(BigDecimal totalCost) {
        this.totalCost = totalCost;
    }

    @Override
    public String toString() {
        return "Goods{" +
            "id=" + id +
            ", product=" + product +
            ", todayCost=" + todayCost +
            ", monthCost=" + monthCost +
            ", totalCost=" + totalCost +
        "}";
    }
}
