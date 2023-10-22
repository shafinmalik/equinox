//
//  GameView.swift
//  equinox
//
//  Created by Shafin Malik on 10/21/23.
//

import MetalKit

class GameView: MTKView {
    var commandQueue: MTLCommandQueue!
    required init(coder: NSCoder) {
        super.init(coder:coder)
        
        self.device = MTLCreateSystemDefaultDevice()
        self.clearColor = MTLClearColorMake(0.43, 0.73, 0.35, 1.0)
        self.colorPixelFormat = .bgra8Unorm
        
        self.commandQueue = device?.makeCommandQueue()
    }
    
    override func draw(_ dirtyRect: NSRect) {
        guard let drawable = self.currentDrawable, let renderPassDescriptor = self.currentRenderPassDescriptor else { return }
        let commandBuffer = commandQueue.makeCommandBuffer()
        let renderCommandEncoder = commandBuffer?.makeRenderCommandEncoder(descriptor: renderPassDescriptor)
    }
    
}
