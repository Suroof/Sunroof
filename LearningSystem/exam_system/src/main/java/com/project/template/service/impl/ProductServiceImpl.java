package com.project.template.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.project.template.dto.ProductDTO;
import com.project.template.entity.Product;
import com.project.template.mapper.ProductMapper;
import com.project.template.service.ProductService;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

@Service
public class ProductServiceImpl extends ServiceImpl<ProductMapper, Product> implements ProductService {

    @Override
    public ProductDTO getProductById(Integer id) {
        Product product = getById(id);
        if (product != null) {
            ProductDTO productDTO = new ProductDTO();
            BeanUtils.copyProperties(product, productDTO);
            return productDTO;
        }
        return null;
    }

    @Override
    public void saveProduct(ProductDTO productDTO) {
        Product product = new Product();
        BeanUtils.copyProperties(productDTO, product);
        save(product);
    }

    @Override
    public void updateProduct(ProductDTO productDTO) {
        Product product = new Product();
        BeanUtils.copyProperties(productDTO, product);
        updateById(product);
    }

    @Override
    public void deleteProduct(Integer id) {
        removeById(id);
    }
}
