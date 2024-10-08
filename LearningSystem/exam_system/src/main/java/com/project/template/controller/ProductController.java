//package com.project.template.controller;
//
//import com.project.template.dto.ProductDTO;
//import com.project.template.service.ProductService;
//import org.springframework.beans.BeanUtils;
//import org.springframework.beans.factory.annotation.Autowired;
//import org.springframework.web.bind.annotation.*;
//
//import java.util.List;
//import java.util.stream.Collectors;
//
//@RestController
//@RequestMapping("/api/product")
//public class ProductController {
//
//    @Autowired
//    private ProductService productService;
//
//    @GetMapping("/{id}")
//    public ProductDTO getProductById(@PathVariable Integer id) {
//        return productService.getProductById(id);
//    }
//
//    @PostMapping
//    public void saveProduct(@RequestBody ProductDTO productDTO) {
//        productService.saveProduct(productDTO);
//    }
//
//    @PutMapping("/{id}")
//    public void updateProduct(@PathVariable Integer id, @RequestBody ProductDTO productDTO) {
//        productDTO.setId(id);
//        productService.updateProduct(productDTO);
//    }
//
//    @DeleteMapping("/{id}")
//    public void deleteProduct(@PathVariable Integer id) {
//        productService.deleteProduct(id);
//    }
//
//    @GetMapping
//    public List<ProductDTO> getAllProducts() {
//        return productService.list().stream().map(product -> {
//            ProductDTO productDTO = new ProductDTO();
//            org.springframework.beans.BeanUtils.copyProperties(product, productDTO);
//            return productDTO;
//        }).collect(Collectors.toList());
//    }
//
//
//}
package com.project.template.controller;

import com.project.template.common.Result;
import com.project.template.dto.ProductDTO;
import com.project.template.entity.Product;
import com.project.template.service.ProductService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/product")
public class ProductController {

    @Autowired
    private ProductService productService;

    @GetMapping("/productlist")
    public Result<List<ProductDTO>> list() {
        List<Product> productList = productService.list();
        List<ProductDTO> productDTOList = productList.stream().map(product -> {
            ProductDTO productDTO = new ProductDTO();
            BeanUtils.copyProperties(product, productDTO);
            return productDTO;
        }).collect(Collectors.toList());
        return new Result<List<ProductDTO>>().success(productDTOList);
    }
}
